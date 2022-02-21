#include "webserver.h"
#include <string.h>
#include "./log/log.h"
#include <signal.h>
WebServer::WebServer()
{
    //http_conn类对象
    users = new http_conn[MAX_FD];

    //root文件夹路径
    char server_path[200];
    getcwd(server_path, 200);
    char root[6] = "/root";
    m_root = (char *)malloc(strlen(server_path) + strlen(root) + 1);
    strcpy(m_root, server_path);
    strcat(m_root, root);

    //定时器
    users_timer = new client_data[MAX_FD];
}

WebServer::~WebServer()
{
    close(m_epollfd);
    close(m_listenfd);
    close(m_pipefd[1]);
    close(m_pipefd[0]);
    delete[] users;
    delete[] users_timer;
    delete m_pool;
}

void WebServer::init(int port, string user, string passWord, string databaseName, int log_write, 
                     int opt_linger, int trigmode, int sql_num, int thread_num, int close_log, int actor_model)
{
    m_port = port;                   //端口号
    m_user = user;                   //用户，登录数据库获取注册的人员信息以及进行人员注册
    m_passWord = passWord;           //密码
    m_databaseName = databaseName;   //数据库的名字（人员信息表在这个数据库里面）
    m_sql_num = sql_num;             //数据库连接池的连接数量
    m_thread_num = thread_num;       //线程池的线程数量
    m_log_write = log_write;         //是否开启异步日志（1表示开启）
    m_OPT_LINGER = opt_linger;       //
    m_TRIGMode = trigmode;           //监听描述符和连接描述符的触发模式：
    m_close_log = close_log;         //是否开启日志
    m_actormodel = actor_model;      //事件处理模式：reactor或者proactor，1表示reactor,0表示proactor
}

void WebServer::trig_mode()
{
    //LT + LT
    if (0 == m_TRIGMode)
    {
        m_LISTENTrigmode = 0;
        m_CONNTrigmode = 0;
    }
    //LT + ET
    else if (1 == m_TRIGMode)
    {
        m_LISTENTrigmode = 0;
        m_CONNTrigmode = 1;
    }
    //ET + LT
    else if (2 == m_TRIGMode)
    {
        m_LISTENTrigmode = 1;
        m_CONNTrigmode = 0;
    }
    //ET + ET
    else if (3 == m_TRIGMode)
    {
        m_LISTENTrigmode = 1;
        m_CONNTrigmode = 1;
    }
}

void WebServer::log_write()
{
    if (0 == m_close_log)
    {
        //初始化日志
        if (1 == m_log_write)
            log::GetInstance()->Init("./ServerLog", m_close_log, 2000, 800000, 800);
        else
            log::GetInstance()->Init("./ServerLog", m_close_log, 2000, 800000, 0);
    }
}

void WebServer::sql_pool()
{
    //初始化数据库连接池
    m_connPool = connection_pool::GetInstance();
    m_connPool->init("localhost", m_user, m_passWord, m_databaseName, 3306, m_sql_num, m_close_log);

    //初始化数据库读取表
    users->initmysql_result(m_connPool);
}

void WebServer::thread_pool()
{
    //线程池
    m_pool = new threadpool<http_conn>(m_actormodel, m_connPool, m_thread_num);
}

void WebServer::eventListen()
{
    //网络编程基础步骤
    m_listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(m_listenfd >= 0);

    //优雅关闭连接
    if (0 == m_OPT_LINGER)
    {
        //不采用优雅关闭连接，默认方式关闭：四次挥手
        struct linger tmp = {0, 1};//第一个参数代表是否开启linger选项，第二的参数是时间
        setsockopt(m_listenfd, SOL_SOCKET, SO_LINGER, &tmp, sizeof(tmp));
    }
    else if (1 == m_OPT_LINGER)
    {
        //第一个1表示开启linger选项，第二个1表示：在1秒内将发送缓冲区的数据发送出去，如果发送不完，直接丢弃剩余的数据，之后执行四次挥手过程
        struct linger tmp = {1, 1};
        setsockopt(m_listenfd, SOL_SOCKET, SO_LINGER, &tmp, sizeof(tmp));
    }

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(m_port);

    int flag = 1;
    setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));//地址重用
    ret = bind(m_listenfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret >= 0);
    ret = listen(m_listenfd, 128);
    assert(ret >= 0);

    utils.Init(TIMESLOT);

    //epoll创建内核事件表
    epoll_event events[MAX_EVENT_NUMBER];
    m_epollfd = epoll_create(5);
    assert(m_epollfd != -1);

    utils.addfd(m_epollfd, m_listenfd, false, m_LISTENTrigmode);
    http_conn::m_epollfd = m_epollfd;

    ret = socketpair(PF_UNIX, SOCK_STREAM, 0, m_pipefd);
    assert(ret != -1);
    utils.SetNoBlocking(m_pipefd[1]);
    utils.addfd(m_epollfd, m_pipefd[0], false, 0);//监听管道的读端的可读事件

    utils.addsig(SIGPIPE, SIG_IGN);
    utils.addsig(SIGALRM, utils.sig_handle, false);
    utils.addsig(SIGTERM, utils.sig_handle, false);

    //alarm(TIMESLOT);

    //工具类,信号和描述符基础操作
    Util::u_pipefd = m_pipefd;
    Util::u_epollfd = m_epollfd;
}

void WebServer::timer(int connfd, struct sockaddr_in client_address)
{
    users[connfd].init(connfd, client_address, m_root, m_CONNTrigmode, m_close_log, m_user, m_passWord, m_databaseName);

    //初始化client_data数据
    //创建定时器，设置回调函数和超时时间，绑定用户数据，将定时器添加到链表中
    users_timer[connfd].address = client_address;
    users_timer[connfd].sockfd = connfd;
    util_time *timer = new util_time();
    timer->user_data = &users_timer[connfd];
    timer->cb_func = cb_func;
    time_t cur = time(NULL);
    timer->expire = cur + 3* TIMESLOT;
    users_timer[connfd].time = timer;
    utils.m_pTime_list.add_time(timer);
}

//若有数据传输，则将定时器往后延迟3个单位
//并对新的定时器在链表上的位置进行调整
void WebServer::adjust_timer(util_time *timer)
{
    time_t cur = time(NULL);
    timer->expire = cur +3* TIMESLOT;
    utils.m_pTime_list.adjust_time(timer);

    LOG_INFO("%s", "adjust timer once");
}

void WebServer::deal_timer(util_time *timer, int sockfd)
{
    timer->cb_func(&users_timer[sockfd]);
    if (timer)
    {
        utils.m_pTime_list.del_time(timer);
    }

    LOG_INFO("close fd %d", users_timer[sockfd].sockfd);
}

bool WebServer::dealclinetdata()
{
    struct sockaddr_in client_address;
    socklen_t client_addrlength = sizeof(client_address);
    if (0 == m_LISTENTrigmode)
    {
        int connfd = accept(m_listenfd, (struct sockaddr *)&client_address, &client_addrlength);
        if (connfd < 0)
        {
            LOG_ERROR("%s:errno is:%d", "accept error", errno);
            return false;
        }
        if (http_conn::m_connfd_num >= MAX_FD)
        {
            utils.show_error(connfd, "Internal server busy");
            LOG_ERROR("%s", "Internal server busy");
            return false;
        }
        timer(connfd, client_address);
    }

    else
    {
        while (1)
        {
            //ET模式只会触发一次，当可读的时候，一定要通过循环读取出所有的数据（此处对于监听套接字而言就是接收所有成功建立的连接）
            int connfd = accept(m_listenfd, (struct sockaddr *)&client_address, &client_addrlength);
            if (connfd < 0)
            {
                LOG_ERROR("%s:errno is:%d", "accept error", errno);
                break;
            }
            if (http_conn::m_connfd_num >= MAX_FD)
            {
                utils.show_error(connfd, "Internal server busy");
                LOG_ERROR("%s", "Internal server busy");
                break;
            }
            timer(connfd, client_address);
        }
        return false;
    }
    return true;
}

bool WebServer::dealwithsignal(bool &timeout, bool &stop_server)
{
    int ret = 0;
    int sig;
    char signals[1024];
    ret = recv(m_pipefd[0], signals, sizeof(signals), 0);
    if (ret == -1)
    {
        return false;
    }
    else if (ret == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < ret; ++i)
        {
            switch (signals[i])
            {
            case SIGALRM:
            {
                timeout = true;
                break;
            }
            case SIGTERM:
            {
                stop_server = true;
                break;
            }
            }
        }
    }
    return true;
}

void WebServer::dealwithread(int sockfd)
{
    util_time *timer = users_timer[sockfd].time;

    //reactor：主线程只监视是否有就绪事件，并把就绪事件通知给工作线程，对于数据的读写、处理，都由工作线程完成
    if (1 == m_actormodel)
    {
        
        if (timer)
        {
            adjust_timer(timer);
        }
        //若监测到读事件，将该事件放入请求队列
        m_pool->append(users + sockfd, 0);//0表示为读事件

        //可以改进的地方：此处会一直循环直到read_once完成
        while (true)
        {
            //
            if (1 == users[sockfd].m_improv)
            {
                if (1 == users[sockfd].m_time_flag)
                {
                    //当写入操作出错的时候，会将m_time_flag置为1，此时关闭连接
                    deal_timer(timer, sockfd);
                    users[sockfd].m_time_flag = 0;
                }
                users[sockfd].m_improv = 0;
                break;
            }
        }
    }
    else
    {
        //proactor：主线程监听就绪事件并进行IO处理，工作线程处理仅业务逻辑，通常使用异步io
        //主线程进行IO，在此期间主线程无法监听事件
        if (users[sockfd].read_once())
        {
            LOG_INFO("deal with the client(%s)", inet_ntoa(users[sockfd].getaddress()->sin_addr));

            //若监测到读事件，将该事件放入请求队列
            m_pool->append_p(users + sockfd);

            if (timer)
            {
                adjust_timer(timer);
            }
        }
        else
        {
            deal_timer(timer, sockfd);
        }
    }
}

void WebServer::dealwithwrite(int sockfd)
{
    util_time *timer = users_timer[sockfd].time;
    //reactor：主线程只监视是否有就绪事件，并把就绪事件通知给工作线程，对于数据的读写、处理，都由工作线程完成
    if (1 == m_actormodel)
    {
        if (timer)
        {
            adjust_timer(timer);
        }

        m_pool->append(users + sockfd, 1);

        //可以改进的地方：此处会一直循环直到write()完成
        while (true)
        {
            //当写操作完成的时候，才会将当前sockfd的m_improv置为1，因此主线程在这里会一直循环，不能再监听其他事件，直到一个写操作的处理完成
            if (1 == users[sockfd].m_improv)
            {
                if (1 == users[sockfd].m_time_flag)
                {
                    //写操作返回错误，会将m_time_flag置为1
                    deal_timer(timer, sockfd);
                    users[sockfd].m_time_flag = 0;
                }
                users[sockfd].m_improv = 0;
                break;
            }
        }
    }
    else
    {
        //proactor：主线程监听就绪事件并进行IO处理，工作线程处理仅业务逻辑，通常使用异步io
        if (users[sockfd].write())
        {
            LOG_INFO("send data to the client(%s)", inet_ntoa(users[sockfd].getaddress()->sin_addr));

            if (timer)
            {
                adjust_timer(timer);
            }
        }
        else
        {
            deal_timer(timer, sockfd);
        }
    }
}

void WebServer::eventLoop()
{
    bool timeout = false;
    bool stop_server = false;

    while (!stop_server)
    {
        int number = epoll_wait(m_epollfd, events, MAX_EVENT_NUMBER, -1);
        if (number < 0 && errno != EINTR)
        {
            LOG_ERROR("%s", "epoll failure");
            break;
        }

        for (int i = 0; i < number; i++)
        {
            int sockfd = events[i].data.fd;

            //处理新到的客户连接
            if (sockfd == m_listenfd)
            {
                bool flag = dealclinetdata();
                if (false == flag)
                    continue;
            }
            else if (events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
            {
                //服务器端将描述符从epoll内核事件表移除，然后关闭连接，最后移除对应的定时器
                util_time *timer = users_timer[sockfd].time;
                deal_timer(timer, sockfd);
            }
            //处理信号
            else if ((sockfd == m_pipefd[0]) && (events[i].events & EPOLLIN))
            {
                bool flag = dealwithsignal(timeout, stop_server);
                if (false == flag)
                    LOG_ERROR("%s", "dealclientdata failure");
            }
            //处理客户连接上接收到的数据
            else if (events[i].events & EPOLLIN)
            {
                dealwithread(sockfd);
            }
            else if (events[i].events & EPOLLOUT)
            {
                dealwithwrite(sockfd);
            }
        }
        if (timeout)
        {
            utils.time_handle();

            LOG_INFO("%s", "timer tick");

            timeout = false;
        }
    }
}