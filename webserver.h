#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <cassert>
#include <sys/epoll.h>

#include "./threadpool/threadpool.h"
#include "./http/http.h"

#include "./time/util_time.h"
//#include "./time/time_wheel.h"
#include "./time/Util.h"
const int MAX_FD = 65536;           //最大文件描述符
const int MAX_EVENT_NUMBER = 10000; //最大事件数
const int TIMESLOT = 5;             //最小超时单位

class WebServer
{
public:
    WebServer();
    ~WebServer();

    void init(int port , string user, string passWord, string databaseName,
              int log_write , int opt_linger, int trigmode, int sql_num,
              int thread_num, int close_log, int actor_model);

    void thread_pool();
    void sql_pool();
    void log_write();
    void trig_mode();
    void eventListen();
    void eventLoop();
    //根据连接套接字创建一个连接对象（http_conn）以及一个定时器并将这个定时器放入定时器链表中
    void timer(int connfd, struct sockaddr_in client_address);
    void adjust_timer(util_time *timer);

    //首先调用timer的回调函数将对应的连接描述符从epoll内核事件表异常，然后关闭套接字
    //然后将timer从定时器链表中移除
    void deal_timer(util_time *timer, int sockfd);
    bool dealclinetdata();
    bool dealwithsignal(bool& timeout, bool& stop_server);
    void dealwithread(int sockfd);
    void dealwithwrite(int sockfd);

public:
    //基础
    int m_port;     //端口好
    char *m_root;
    int m_log_write;  //是否开启异步日志
    int m_close_log;  //是否开启日志
    int m_actormodel; //事件处理模式：1表示reactor,0表示proactor

    int m_pipefd[2];  //管道
    int m_epollfd;    //epoll
    http_conn *users; //连接（指向一个动态创建的数组）

    //数据库相关
    connection_pool *m_connPool;
    string m_user;         //登陆数据库用户名
    string m_passWord;     //登陆数据库密码
    string m_databaseName; //使用数据库名
    int m_sql_num;         //数据库连接池的最大连接数

    //线程池相关
    threadpool<http_conn> *m_pool;  //线程池（动态创建）
    int m_thread_num;               //线程数量

    //epoll_event相关
    epoll_event events[MAX_EVENT_NUMBER];

    int m_listenfd;  //监听套接字
    int m_OPT_LINGER; //
    int m_TRIGMode;   //描述符的触发模式（实际上仅仅是监听套接字和连接套接字的触发模式的组合2*2共四个值，代表四种组合）
    int m_LISTENTrigmode;//监听套接字的触发模式：0-LT,1-ET
    int m_CONNTrigmode;  //连接套接字的触发模式;0-LT,1-ET

    //定时器相关
    client_data *users_timer;  //定时器（指向动态创建的数组）
    Util utils;         
};
#endif
