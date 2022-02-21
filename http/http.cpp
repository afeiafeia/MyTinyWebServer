#include "http.h"
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <error.h>
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/mman.h>
#include <bits/mman-linux.h>
#include <fstream>
#include <sys/uio.h>
#include <sys/unistd.h>
#include "../CGImysql/connectionRAII.h"
#include "../log/log.h"
int http_conn::m_epollfd = 0;
int http_conn::m_connfd_num = 0;
//定义http响应的一些状态信息
const char *ok_200_title = "OK";
const char *error_400_title = "Bad Request";
const char *error_400_form = "Your request has bad syntax or is inherently impossible to staisfy.\n";
const char *error_403_title = "Forbidden";
const char *error_403_form = "You do not have permission to get file form this server.\n";
const char *error_404_title = "Not Found";
const char *error_404_form = "The requested file was not found on this server.\n";
const char *error_500_title = "Internal Error";
const char *error_500_form = "There was an unusual problem serving the request file.\n";

locker m_lock;
map<string, string> users;

void http_conn::init(int sockfd,sockaddr_in &iAddr,char* root,int TRIGMode,int close_log,string user,string passwd,string sqlname)
{
    m_connfd_num++;
    m_sockfd   = sockfd;
    m_addr     = iAddr;
    m_TRIGMode = TRIGMode;
    m_root = root;
    m_close_log = close_log;
    strcpy(sql_user,user.c_str());
    strcpy(sql_passwd,passwd.c_str());
    strcpy(sql_name,sqlname.c_str());

    
    addfd(m_epollfd,true);
    init();
}
void http_conn::init()
{
    m_check_state = CHECK_STATE_REQUESTLINE;
    m_url = nullptr;
    m_version = nullptr;
    m_method = GET;
    m_ContentLength = 0;
    //m_content = nullptr;
    m_read_index = 0;
    m_check_idx = 0;
    m_start_line = 0;
    memset(m_read_buff,'\0',READ_BUFF_SIZE);

    byte_have_send = 0;
    byte_to_send = 0;
    m_write_index = 0;
    memset(m_write_buff,'\0',WRITE_BUFF_SIZE);

    m_linger = false;
    memset(m_real_file_path,'\0',256);

    m_improv = 0;
    m_time_flag = 0;
}

int http_conn::SetNoBlock()
{
    int old_option = fcntl(m_sockfd,F_GETFL);
    int new_option = old_option|O_NONBLOCK;
    fcntl(m_sockfd,F_SETFL,new_option);
    return old_option;
}

void http_conn::addfd(int epollfd,bool one_shot)
{
    epoll_event event;
    event.data.fd = m_sockfd;
    if(m_TRIGMode==1)
    {
        event.events = EPOLLIN|EPOLLET||EPOLLRDHUP;
    }
    else
    {
        event.events = EPOLLIN|EPOLLRDHUP;
    }
    if(one_shot)
    {
        event.events|=EPOLLONESHOT;
    }
    epoll_ctl(epollfd,EPOLL_CTL_ADD,m_sockfd,&event);
    SetNoBlock();

}

bool http_conn::read_once()
{
    if(m_read_index>READ_BUFF_SIZE)
    {
        return false;
    }
    int byte_read = 0;
    if(m_TRIGMode==0)
    {
        //LT模式：如果没读取完，则在process_read中会返回NO_REQUEST，会重新注册读取事件，由其他线程继续处理（注意这时之前的数据已经读到缓冲区里面，其他线程继续读取后面的数据就行）
        //而ET模式，由于触发条件是状态的切换，因此，如果没读取完，继续监视，也不会再触发，所以ET模式是采用循环读取直至读取完
        byte_read = recv(m_sockfd,m_read_buff+m_read_index,READ_BUFF_SIZE-m_read_index,0);
        if(byte_read<=0)
        {
            LOG_ERROR("Error:%s","Error In recv!");
            return false;
        }
        m_read_index+=byte_read;
        //LOG_DEBUG("%s",m_read_buff);
        LOG_INFO("Accept:%s",m_read_buff);
        return true;
    }
    else
    {
        //ET模式
        //ET模式要循环读，直至读到EAGAIN或者EWOULDBLOCK
        //因为ET模式只触发一次，如果漏读或者没读取完，不会再触发可读事件（后续再有数据到达也不会触发）
        while(true)
        {
            byte_read = recv(m_sockfd,m_read_buff+m_read_index,READ_BUFF_SIZE-m_read_index,0);
            if(byte_read==-1)
            {
                if(errno==EAGAIN || errno==EWOULDBLOCK)
                {
                    break;
                }
                LOG_ERROR("Error:%s","Error In recv!");
                return false;
            }
            else if(byte_read==0)
            {
                LOG_ERROR("Error:%s","Error In recv!");
                return false;
            }
            m_read_index+=byte_read;
        }
        LOG_INFO("Accept:%s",m_read_buff);
        return true;
    }



    //虽然读操作完成，但此时并不会重新监测读事件，
    //会在之后调用write中发送响应报文，发送完成才会再次监测可读事件
    //因此，这种方式只能串行的处理请求，如果前一个请求的响应没完成，后续的请求就会一直等待；
    //因此，如果请求了多个对象，客户端可能会有较大延迟

    //如果在此处重新监测套接字上的可读事件，会存在什么问题？
    //（1）:如果一个http报文没有读取完整（有一部分报文还没到），那此时这个工作线程正在处理其他事情，当后续报文到达后，变为可读，会被其它线程读取，这将导致一个http请求报文被多个线程同时处理的情况发生
}


void http_conn::process()
{
    HTTP_STATE read_ret = process_read();
    if(read_ret == NO_REQUEST)
    {
        //请求报文不完整，需要继续监测读事件
        modfd(EPOLLIN);
        return;
    }
    bool write_ret = process_write(read_ret);
    if(!write_ret)
    {
        close(m_sockfd);
    }

    modfd(EPOLLOUT);//将相应报文放在了发送缓冲区，开始监视可读事件，可读时把响应报文发送出去

    //此时并不会重新监测读事件，
    //会在之后调用write中发送响应报文，发送完成才会再次监测可读事件

}

 http_conn::LINE_STATE http_conn::parse_line()
{
    char tmp;
    for(;m_check_idx<m_read_index;m_check_idx++)
    {
        tmp = m_read_buff[m_check_idx];
        //如果当前是\r字符，则有可能会读取到完整的行
        if(tmp=='\r')
        {
            //\r是读取到的最后一个字符：说明读取到的行不完整
            if(m_check_idx+1==m_read_index)
            {
                return LINE_OPEN;
            }
            //下一个字符是换行符：读取到了完整的一行
            else if(m_read_buff[m_check_idx+1] =='\n')
            {
                m_read_buff[m_check_idx++]='\0';
                m_read_buff[m_check_idx++]='\0';//此时m_check_idx为下一行的第一个字节的下标
                return LINE_OK;
            }
            //如果都不符合，返回语法错误
            return LINE_BAD;
        }

        //也可能没有\r，直接是\n,一般是上次接受到|\r就到末尾了，之后后续报文到达，再次读取时，直接读取\n
        else if(tmp=='\n')
        {
            if(m_check_idx>0&&m_read_buff[m_check_idx-1]=='\r')
            {
                m_read_buff[m_check_idx-1]='\0';
                m_read_buff[m_check_idx++]='\0';
                return LINE_OK;
            }

            return LINE_BAD;
        }
    }

    return LINE_BAD;
}
char* http_conn::GetCurLine()
{
    return m_read_buff+m_start_line;
}
http_conn::HTTP_STATE http_conn::process_read()
{
    //初始化从状态机状态
    LINE_STATE line_state = LINE_OK;
    HTTP_STATE ret = NO_REQUEST;
    char* pCurLine= nullptr;

    while((m_check_state==CHECK_STATE_CONTNET&&line_state==LINE_OK)||((line_state=parse_line())==LINE_OK))
    {
        //实体体不会被parse_line解析，当m_check_state==CHECK_STATE_CONTNET时，不会调用后面对parse_line，因此，m_check_index此时指向实体体的开头
        pCurLine = GetCurLine();
        m_start_line = m_check_idx;

        switch(m_check_state)
        {
            case CHECK_STATE_REQUESTLINE:
            {
                ret = parse_request_line(pCurLine);
                if(ret==BAD_REQUEST)
                {
                    return BAD_REQUEST;
                }
                break;
            }
            case CHECK_STATE_HEADER:
            {
                ret = parse_headers(pCurLine);
                if(ret==BAD_REQUEST)
                {
                    return BAD_REQUEST;
                }
                else if(ret==GET_REQUEST)
                {
                    //CHECK_STATE_HEADER状态下，只有在是Get请求时，才会返回Get_REQUEST
                    return do_request();
                }
                break;
            }
            case CHECK_STATE_CONTNET:
            {
                ret = parse_content(pCurLine);   
                if(ret==GET_REQUEST)
                {
                    return do_request();
                }           
                line_state = LINE_OPEN;
                break;
            }
            default:
            return INTERNAL_ERROR;
        }
    }
    return NO_REQUEST;

}


http_conn::HTTP_STATE http_conn::parse_request_line(char* ipCurLine)
{
     //char* strpbrk(const char* str1,const char* str2)
    //检索字符串str1中第一个匹配字符串str2的字符；遍历str1中的字符，查看其是否在str2中

    //http报文的第一行是请求行，有三个字段：方法、URL、版本
    //这三个字段通过\t或者空格分隔
    m_url = strpbrk(ipCurLine," \t");//如果存在m_url,此时m_url指向URL的前一个位置
    if(m_url==nullptr)
    {
        return BAD_REQUEST;
    }
    *m_url++ = '\0';

    char* pMethod = ipCurLine;
    //nt strcasecmp (const char *__s1, const char *__s2):比较两个字符串（忽略大小写），相等则返回0,，s1长，则返回值大于0,否则小于0
    if(strcasecmp(pMethod,"GET")==0)
    {
        m_method = GET;
    }
    else if(strcasecmp(pMethod,"POST")==0)
    {
        m_method = POST;
        m_cgi=1;
    }
    else
    {
        return BAD_REQUEST;
    }
 
    //size_t strspn(const char* str1,const char* str2);在str1中检索第一个不在str2中的字符的下标
    //m_url此时跳过了第一个空格或\t字符，但不知道之后是否还有
    //将m_url向后偏移，通过查找，继续跳过空格和\t字符，指向请求资源的第一个字符
    m_url+=strspn(m_url," \t");

    //版本
    m_version = strpbrk(m_url," \t");
    *m_version++ = '\0';

    m_version+=strspn(m_version," \t");

    //目前仅支持http/1.1
    if(strncasecmp(m_version,"HTTP/1.1",7)!=0)
    {
        return BAD_REQUEST;
    }
    if(strncasecmp(m_url,"http://",7)==0)
    {
        m_url+=7;
        //char *strchr(const char *str, int c);
        //在str所指向的字符串中检索字符c第一次出现的位置
        m_url = strchr(m_url,'/');
    }
    if(strncasecmp(m_url,"https://",8)==0)
    {
        //https协议
        m_url+=8;
        m_url = strchr(m_url,'/');
    }

    if(!m_url||m_url[0]!='/')
    {
        return BAD_REQUEST;
    }

    if(strlen(m_url)==1)
    {
        strcat(m_url,"judge.html");
    }
    m_check_state = CHECK_STATE_HEADER;
    return NO_REQUEST;
}

//http报文由上之下，每一行依次是：
//请求行
//首部行（会有多个）
//空行：用来分隔首部行和实体体
//实体体

http_conn::HTTP_STATE http_conn::parse_headers(char* ipCurLine)
{
    if(ipCurLine[0]=='\0')
    {
        //当前行开头即是\0，说明是空行
        if(m_ContentLength>0)
        {
            //存在实体体:说明是POST请求，切换主状态机的状态
            m_check_state = CHECK_STATE_CONTNET;
            return NO_REQUEST;
        }
        //否则说明是GET请求
        return GET_REQUEST;
    }
    else if(strncasecmp(ipCurLine,"Connection:",11)==0)
    {
        //Connection字段
        ipCurLine+=11;
        ipCurLine+=strspn(ipCurLine," \t");
        if(strcasecmp(ipCurLine,"keep-alive")==0)
        {
            //keep-alive表示这个http是长连接
            //如果为close，则是短连接
            m_linger = true;
        }
    }
    else if(strncasecmp(ipCurLine,"Content-Length:",15)==0)
    {
        //实体体长度
        ipCurLine+=15;
        ipCurLine+=strspn(ipCurLine," \t");
        m_ContentLength = atol(ipCurLine);
    }
    else if (strncasecmp(ipCurLine,"User-Agent:",11)==0)
    {
        ipCurLine+=11;
        ipCurLine+=strspn(ipCurLine," \t");
        m_browser = ipCurLine;
    }
    else if(strncasecmp(ipCurLine,"Host:",5)==0)
    {
        //主机域名
        ipCurLine+=5;
        ipCurLine+=strspn(ipCurLine," \t");
        m_host = ipCurLine;
    }

    return NO_REQUEST;
}


http_conn::HTTP_STATE http_conn::parse_content(char* ipCurLine)
{
    if(m_read_index>=(m_ContentLength+m_check_idx))
    {
        //实体体的末尾不带\r\n
        ipCurLine[m_ContentLength]='\0';
        m_content = ipCurLine;
        return GET_REQUEST;
    }
    return NO_REQUEST;
}


void http_conn::modfd(int event)
{
    epoll_event curEvent;
    curEvent.data.fd = m_sockfd;
    if(m_TRIGMode==1)
    {
        //ET模式
        curEvent.events = event|EPOLLET|EPOLLONESHOT|EPOLLRDHUP;
    }
    else
    {
        curEvent.events = event|EPOLLONESHOT|EPOLLRDHUP;
    }
    epoll_ctl(m_epollfd,EPOLL_CTL_MOD,m_sockfd,&curEvent);

}

http_conn::HTTP_STATE http_conn::do_request()
{
    //将m_real_file_path设置为根目录
    strcpy(m_real_file_path,m_root);

    int len = strlen(m_real_file_path);

    //找到m_url中字符'/'的位置
    const char* p = strrchr(m_url,'/');//在m_url所指向的字符串中检索字符'/'最后一次出现的位置
    if(m_cgi==1&&(*(p+1)=='2'||*(p+1)=='3'))
    {
        //说明是m_cgi==1说明是post请求，*(p+1)=='2'或者*(p+1)=='3'说明是登录监测或者注册监测
        //对应的步骤是：注册账号密码之后点击提交或者输入账号密码之后点击确定，这里是通过'2'和'3'区分，这一步所解析的post请求的报文中，包含了账号和密码
        char url_real[256]={'\0'};
        strcpy(url_real,"/");
        strcat(url_real,m_url+2);
        strncpy(m_real_file_path+len,url_real,FILENAME_MAX-len-1);//-1是因为最后一位是预留给'/0';

        //提起用户名和密码:其在报文中的格式是user=xyz&passwd=abcd;//xyz、abcd表示任意数量任意字符
        char name[256] = {'\0'};
        char passwd[256] = {'\0'};
        char* userSt = strchr(const_cast<char*>(m_content.c_str()),'=');
        userSt++;
        char* passwdSt = strrchr(const_cast<char*>(m_content.c_str()),'=');
        passwdSt++;
        int i=0;
        for(;userSt[i]!='&';i++)
        {
            name[i] = userSt[i];
        }
        int j=0;
        for(;passwdSt[j]!='\0';j++)
        {
            passwd[j] = passwdSt[j];
        }
        if(*(p+1)=='3')
        {
            //是注册
            //如果是注册，先检测数据库中是否有重名的
            //没有重名的，进行增加数据
            char *sql_insert = (char *)malloc(sizeof(char) * 200);
            strcpy(sql_insert, "INSERT INTO user(username, passwd) VALUES(");
            strcat(sql_insert, "'");
            strcat(sql_insert, name);
            strcat(sql_insert, "', '");
            strcat(sql_insert, passwd);
            strcat(sql_insert, "')");

            if (users.find(name) == users.end())
            {
                m_lock.Lock();
                int res = mysql_query(mysql, sql_insert);
                users.insert(pair<string, string>(name, passwd));
                m_lock.UnLock();

                if (!res)
                    strcpy(m_url, "/log.html");
                else
                    strcpy(m_url, "/registerError.html");
            }
            else
                strcpy(m_url, "/registerError.html");

        }
        //如果是登录，直接判断
        //若浏览器端输入的用户名和密码在表中可以查找到，返回1，否则返回0
        else if (*(p + 1) == '2')
        {
            if (users.find(name) != users.end() && users[name] == passwd)
                strcpy(m_url, "/welcome.html");
            else
                strcpy(m_url, "/logError.html");
        }

    }

    //为注册请求，跳转到注册页面register.html
    if(*(p+1)=='0')
    {
        const char* pResource = "/register.html";
        int length = strlen(pResource);
        strncpy(m_real_file_path+len,pResource,length);
    }
    //为登录请求，跳转到登录页面log.html
    else if(*(p+1)=='1')
    {
        const char* pResource = "/log.html";
        int length = strlen(pResource);
        strncpy(m_real_file_path+len,pResource,length);
    }
    else if(*(p+1)=='5')
    {
        //既不是注册也不是登录，是请求资源
        //这里的处理是响应欢迎界面
        //请求图片资源
        const char* pPicture = "/picture.html";
        int length = strlen(pPicture);
        strncpy(m_real_file_path+len,pPicture,length);
    }
    else if(*(p+1)=='6')
    {
        //请求视频资源
        const char* pVideo = "/video.html";
        int length = strlen(pVideo);
        strncpy(m_real_file_path+len,pVideo,length);
    }

    else if(*(p+1)=='7')
    {
        //请求fans资源
        const char* pFans= "/fans.html";
        int length = strlen(pFans);
        strncpy(m_real_file_path+len,pFans,length);
    }
    else
    {
        strncpy(m_real_file_path+len,m_url,FILENAME_MAX-len-1);
    }
    //通过stat函数获取请求的资源的属性信息
    if(stat(m_real_file_path,&m_file_stat)<0)
    {
        return NO_REQUEST;
    }

    //文件类型是目录
    if(S_ISDIR(m_file_stat.st_mode))
    {
        return BAD_REQUEST;
    }
    //以只读方式获取文件描述符，通过mmap将该文件映射到内存中
    int fd=open(m_real_file_path,O_RDONLY);
    m_file_address=(char*)mmap(0,m_file_stat.st_size,PROT_READ,MAP_PRIVATE,fd,0);

    //避免文件描述符的浪费和占用
    close(fd);

    //表示请求文件存在，且可以访问
    return FILE_REQUEST;


}

bool http_conn::process_write(http_conn::HTTP_STATE ret)
{
    //http响应报文格式
    /*
    状态行：版本\t状态码\t状态信息\r\n   //add_status_line:
    首部行
    空 行：\r\n
    实体体
    */
   
   switch(ret)
   {
       case INTERNAL_ERROR:
       {
           //内部错误 500
           add_status_line(500,error_500_title);
           add_header(strlen(error_500_title));
           if(!add_content(error_500_form))
           {
               return false;
           }
           break;
       }

       case BAD_REQUEST:
       {
           //报文语法有误 404
           add_status_line(404,error_404_title);
            add_header(strlen(error_404_title));
           if(!add_content(error_404_form))
           {
               return false;
           }
           break;
       }
       case FORBIDDEN_REQUEST:
       {
           //没有访问权限  403
            //报文语法有误 404
           add_status_line(403,error_403_title);
           add_header(strlen(error_403_title));
           if(!add_content(error_403_form))
           {
               return false;
           }
           break;
       }
       case FILE_REQUEST:
       {
           add_status_line(200,ok_200_title);
           if(m_file_stat.st_size!=0)
           {
               //使用IO向量机制，第一个iovec指向m_write_buff,存储的是相应报文的状态行、首部行、空行
               //第二个iovec指向请求的文件所映射到的地址
               add_header(m_file_stat.st_size);
               m_io[0].iov_base = m_write_buff;
               m_io[0].iov_len = m_write_index;

               m_io[1].iov_base = m_file_address;
               m_io[1].iov_len = m_file_stat.st_size;
               m_io_count = 2;
               byte_to_send = m_write_index+m_file_stat.st_size;
               return true;


           }
           else
           {
               //如果请求的资源大小为0，则返回空白html文件
               const char* ok_string="<html><body></body></html>";
               add_header(strlen(ok_string));
               if(!add_content(ok_string))
                   return false;
           }
           break;
       }


       m_io[0].iov_base = m_write_buff;
       m_io[0].iov_len = m_write_index;
       m_io_count = 1;

       return true;
   }
}


bool http_conn::add_response(const char* format,...)
{
    if(m_write_index>=WRITE_BUFF_SIZE)
    {
        return false;
    }
    va_list valist;
    va_start(valist,format);
    int len = vsnprintf(m_write_buff+m_write_index,WRITE_BUFF_SIZE-1-m_write_index,format,valist);
    if(len>=WRITE_BUFF_SIZE-1-m_write_index)
    {
        va_end(valist);
        return false;
    }
    m_write_index+=len;
    va_end(valist);

    //LOG_INFO("request:%s", m_write_buff);
    return true;
}

bool http_conn::add_status_line(int status,const char* title)
{
    return add_response("%s %d %s \r\n","HTTP/1.1",status,title);
}
//添加消息报头
bool http_conn::add_header(int connext_status)
{
    add_content_length(connext_status);
    add_connection();
    add_blank_line();
}
//向首部行添加conteng_len字段，表示响应报文实体体的长度
bool http_conn::add_content_length(int content_len)
{
    return add_response("Content-Length: %d\r\n",content_len);
}
//添加文本类型content_Type字段
bool http_conn::add_content_type()
{
    return add_response("Content-Type: %s\r\n","text/html");
}
//添加连接状态connection字段：close(短连接)或者keep-alive（长连接）
bool http_conn::add_connection()
{
    return add_response("Connection: %s\r\n",m_linger?"keep-alive":"close");
}
//添加空行
bool http_conn::add_blank_line()
{
    return add_response("%s","\r\n");
}
//添加实体体
bool http_conn::add_content(const char* content)
{
    return add_response("%s",content);
}


bool http_conn::write()
{
    int tmp = 0;
    int newadd = 0;
    if(byte_to_send==0)
    {
        modfd(EPOLLIN);
        init();
        return true;
    }
    while(1)
    {
        tmp = writev(m_sockfd,m_io,m_io_count);
        if(tmp>0)
        {
            byte_have_send += tmp;
            newadd = byte_have_send-m_write_index;
        }
        if(tmp<=-1)
        {
            //可能是发送缓冲区满了
            if(errno==EAGAIN||errno==EWOULDBLOCK)
            {
                if(byte_have_send>=m_write_index)
                {
                    m_io[0].iov_len = 0;
                    m_io[1].iov_base = m_file_address+byte_have_send-m_write_index;
                    m_io[1].iov_len = byte_to_send;
                }
                else
                {
                    m_io[0].iov_base = m_write_buff+byte_have_send;
                    m_io[0].iov_len  = m_write_index - byte_have_send;
                }
                //重新注册写事件，等线程下一次写
                //没有注册读事件，因此，如果发送缓冲区满了，将不能接收该连接上的下一个请求
                modfd(EPOLLOUT);
                return true;
            }

            munmap(m_file_address, m_file_stat.st_size);
            return false;
        }
        byte_to_send-=tmp;
        if(byte_to_send<=0)
        {
            //发送完毕
            munmap(m_file_address,m_file_stat.st_size);
            modfd(EPOLLIN);
            if(m_linger)
            {
                init();
                return true;
            }
            else
            {
                //返回false，将使得服务器断开连接
                return false;
            }
        }
    }
}


void http_conn::initmysql_result(connection_pool* ipConnPool)
{
    //先从连接池获取一个连接
    MYSQL* mysql = NULL;
    connectionRAII mysqlConn(&mysql,ipConnPool);

    if(mysql_query(mysql,"SELECT username passwd FROM user"))
    {
        LOG_ERROR("Failed To Select * From user!\n");
    }
    MYSQL_RES* result = mysql_store_result(mysql);
    if(result==nullptr)
    {
        LOG_ERROR("Query Result Is NULL!\n");
    }
    //返回结果集中的列数

    int num_fields = mysql_num_fields(result);
    MYSQL_FIELD* fields = mysql_fetch_fields(result);

    while(MYSQL_ROW row = mysql_fetch_row(result))
    {
        string name(row[0]);
        string passwd(row[0]);
        users[name] = passwd;
    }

}