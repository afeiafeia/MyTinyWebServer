#ifndef EPOLL_POLLER_H
#define EPOLL_POLLER_H

#include <vector>
#include <memory>
#include <sys/epoll.h>
#include "Poller.h"
namespace afa
{
    class EventLoop;
    class Channel;
    class EpollPoller:public Poller
    {
    public:
        typedef std::shared_ptr<Channel> SP_Channel;
    private:
        int m_epollfd;
        std::vector<epoll_event> m_vctEvents;

    public:
        EpollPoller(EventLoop* loop);
        ~EpollPoller();

        void UpdateChannel(SP_Channel spChannel);

        void RemoveChannel(SP_Channel spChannel);

        void EpollAdd(SP_Channel schannel,int timeout=5);
        void EpollDel(SP_Channel schannel,int timeout=5);
        void EpollMod(SP_Channel schannel);

        void Poll(std::vector<SP_Channel> &oActiveChannel);

    };
}


#endif