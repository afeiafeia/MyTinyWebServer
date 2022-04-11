#ifndef MY_TINY_WEB_UTIL_H
#define MY_TINY_WEB_UTIL_H
#include "util_time.h"

class Util
{

public:
    static int *u_pipefd;
    static int u_epollfd;
    int        m_timeslot; //时间间隔：每隔这些秒触发一次SIGALARM信号
    sort_time_list m_pTime_list;

    //time_wheel m_pTime_list;
public:

    Util(){};
    ~Util(){};

    //初始化：timeslot表示时间间隔，每隔timeslot秒触发一次始终信号
    void Init(int timeslot);
    //将描述符设置成非阻塞的
    int SetNoBlocking(int fd);

    //向epoll中添加监视的描述符。监听可读事件并将其设置成非阻塞模式
    void addfd(int epollfd,int fd,bool one_shot,int TRIGMode);

    //信号处理函数：收到信号时调用
    //为什么是静态函数：没有this指针，成员函数默认有一个this指针参数
    //而信号函数要是void（funName）(int)类型
    //执行的操作是：往管道写入信号的编号（目前存在两种情况：SIG_ALARM（时钟信号）和SIG_TERM（程序终止信号））
    static void sig_handle(int sigNo);

    //设置信号处理函数
    void addsig(int sig,void (handle)(int),bool restart = true);

    //在定时器链表中删除过期的节点，然后重新计时
    void time_handle();

    void show_error(int connfd,const char* info);


};

//从epoll内核事件表中移除user_data对应的描述符，并关闭描述符
//它是定时器链表的节点的一个回调函数
void cb_func(client_data* user_data);



#endif