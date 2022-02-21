#include "Util.h"
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>

int *Util::u_pipefd = 0;
int  Util::u_epollfd = 0;
void Util::Init(int timeslot)
{
    m_timeslot = timeslot;
}

int Util::SetNoBlocking(int fd)
{
    int old_option = fcntl(fd,F_GETFD);
    int new_option = old_option|O_NONBLOCK;
    fcntl(fd,F_SETFD,new_option);
    return old_option;
}

void Util::addfd(int epollfd,int fd,bool one_shot,int TRIGMode)
{
    epoll_event curEvent;
    curEvent.data.fd = fd;
    curEvent.events = EPOLLIN|EPOLLRDHUP;
    if(one_shot)
    {
        curEvent.events|=EPOLLONESHOT;
    }
    if(TRIGMode==1)
    {
        curEvent.events|=EPOLLET;
    }
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&curEvent);
    SetNoBlocking(fd);
}

void Util::sig_handle(int sigNO)
{
    int old_errno = errno;
    int msg = sigNO;
    send(u_pipefd[1],(char*)(&sigNO),1,0);
    errno = old_errno;
}

void Util::addsig(int sig,void(handle)(int),bool restart)
{
    struct sigaction sa;
    memset(&sa,'\0',sizeof(sa));
    sa.sa_handler = handle;
    if(restart)
    {
        //SA_RESTART用于重启被信号中断的系统调用
        sa.sa_flags|=SA_RESTART;
    }
    sigfillset(&sa.sa_mask);
    //sigacction(int sig,const struct* act,struct sigaction* oact)
    //sig为信号类型；act为设置的信号处理函数，oact为该信号原来的信号处理函数
    //如果失败，返回-1；

    //作用与signal函数相同
    //_sighandler_t signal (int sig,_sighandler_t _handler);
    //sig是信号类型，_handler是新的信号处理函数，返回值为之前的信号处理函数，
    //如果失败，返回SIG_ERR，
    assert(sigaction(sig,&sa,NULL)!=-1);
}

void Util::time_handle()
{
    m_pTime_list.tick();
    alarm(m_timeslot);
}

void cb_func(client_data* user_data)
{
    epoll_ctl(Util::u_epollfd,EPOLL_CTL_DEL,user_data->sockfd,0);
    close(user_data->sockfd);

}

void Util::show_error(int connfd,const char* info)
{
    send(connfd,info,strlen(info),0);
    close(connfd);
}