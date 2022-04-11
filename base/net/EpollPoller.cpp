#include "EpollPoller.h"
#include "Channel.h"
#include <assert.h>
#include <unistd.h>
namespace afa
{
    EpollPoller::EpollPoller(EventLoop* loop)
    :m_epollfd(epoll_create(1))
    {
         m_loop = loop;
    }

    EpollPoller::~EpollPoller()
    {
        close(m_epollfd);
    }

    void EpollPoller::EpollAdd(SP_Channel channel,int timeout)
    {
        //timeout用来设置定时器

        int fd = channel->Getfd();
        struct epoll_event ev;
        ev.data.fd = fd;
        ev.events = channel->GetEvents();
        int error = epoll_ctl(m_epollfd,EPOLL_CTL_ADD,fd,&ev);
        if(error<0)
        {
            perror("error in epoll_add!\n");
        }
    }

    void EpollPoller::EpollDel(SP_Channel channel,int timeout)
    {
        int fd = channel->Getfd();
        struct epoll_event ev;
        ev.data.fd = fd;
        ev.events = channel->GetEvents();
        if((epoll_ctl(m_epollfd,EPOLL_CTL_DEL,fd,&ev))<0)
        {
            perror("error in epoll_del!\n");
        }
    }

    void EpollPoller::EpollMod(SP_Channel channel)
    {
        int fd = channel->Getfd();
        struct epoll_event ev;
        ev.data.fd = fd;
        ev.events = channel->GetEvents();
        if((epoll_ctl(m_epollfd,EPOLL_CTL_MOD,fd,&ev))<0)
        {
            perror("error in epoll_mod!\n");
        }
    }

    void EpollPoller::UpdateChannel(SP_Channel pChannel)
    {
        int index = pChannel->GetIndex();
        if(index==-1)
        {
            //-1表示之前该套接字不在监听范围，2表示从之前的监听范围移除
            int fd = pChannel->Getfd();
            //如果括号内表达式为false，将输出错误消息程序退出，如果为true，继续往后执行
            assert(mapChannel.find(fd)==mapChannel.end());
            mapChannel[fd] = pChannel;
            EpollAdd(pChannel);
            pChannel->SetIndex(1);

            
        }
        else
        {
            //修改已经存在的文件描述符的监听事件
            int fd = pChannel->Getfd();
            assert(mapChannel.find(fd)!=mapChannel.end());
            EpollMod(pChannel);
        }
    }

    void EpollPoller::RemoveChannel(SP_Channel pChannel)
    {
        if(pChannel==nullptr)
        {
            return;
        }
        int fd = pChannel->Getfd();
        if(mapChannel.find(fd)==mapChannel.end())
        {
            return;
        }
        mapChannel.erase(fd);
        EpollDel(pChannel);

    }

    void EpollPoller::Poll(std::vector<SP_Channel> &oActiveChannel)
    {
        struct epoll_event events[1000];
        int num = epoll_wait(m_epollfd,events,1000,-1);
        for(int i=0;i<num;i++)
        {
            int fd = events[i].data.fd;
            assert(mapChannel.find(fd)!=mapChannel.end());
            SP_Channel pChannel = mapChannel[fd];
            __int32_t curEvent = events[i].events;
            pChannel->SetEvents(curEvent);
            oActiveChannel.push_back(pChannel);
        }
    }




}