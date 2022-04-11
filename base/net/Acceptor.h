#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include <functional>
#include <memory>
#include "Channel.h"
class EventLoop;
namespace afa
{
    class Acceptor
    {
    public:
        typedef std::function<void(void*)> CallBack;
        typedef std::function<void (int sockfd,sockaddr* addr,socklen_t len)> NewConnectionCallBack;

    private:
        EventLoop*               m_baseLoop;
        int                      m_listenfd;  //监听套接字
        __int32_t                m_port;      //所监听端口
        std::unique_ptr<Channel> m_channel;   //监听套接字对应的channel
        NewConnectionCallBack    m_newConnectionCB; //先连接到来时调用的函数，对连接套接字处理

    public:
        Acceptor(int port,EventLoop* baseLoop);
        ~Acceptor();

        void Listen();

        void NewAccept();

        void SetNewConnectionCB(const NewConnectionCallBack &cb)
        {
            m_newConnectionCB = cb;
        }
    };
}


#endif