#include "Channel.h"
#include "EventLoop.h"
#include <unistd.h>
#define POLLIN 0x001
#define POLLPRI 0x002
#define POLLOUT 0x004

namespace afa
{
    const int Channel::s_readEvent = POLLIN|POLLPRI;
    const int Channel::s_writeEvent = POLLOUT;



    Channel::Channel(int fd,EventLoop* loop)
    :m_fd(fd)
    ,m_loop(loop)
    ,m_events(0)
    ,m_index(-1)
    {
    }

    Channel::~Channel()
    {
        close(m_fd);
    }

    void Channel::ReadHandler()
    {
        if(m_readHandler)
        m_readHandler();
    }
    void Channel::WriteHandler()
    {
        if(m_writeHandler)
        m_writeHandler();
    }
    void Channel::ErrorHandler()
    {
        if(m_errorHandler)
        m_errorHandler();
    }
    void Channel::ConnectHandler()
    {
        if(m_connHandler)
        m_connHandler();
    }

    void Channel::HandleEvent()
    {
        if((m_events&EPOLLHUP)&&!(m_events&EPOLLIN))
        {
            m_events = 0;
            return ;
        }
        else if(m_events&(EPOLLIN|EPOLLPRI|EPOLLRDHUP))
        {
            ReadHandler();
        }
        else if(m_events&EPOLLOUT)
        {
            WriteHandler();
        }
        else if(m_events&EPOLLERR)
        {
            if(m_errorHandler)
            {
                ErrorHandler();
            }
            m_events = 0;
            return;
        }
    }

    void Channel::Update()
    {
        m_loop->UpdateChannel(shared_from_this());
    }
    void Channel::Remove()
    {
        m_loop->RemoveChannel(shared_from_this());
    }
}