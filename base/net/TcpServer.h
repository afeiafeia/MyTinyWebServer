#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include <memory>
#include <functional>
namespace afa
{
    class EventLoop;
    class Acceptor;
    class EventLoopThreadPool;
    class TcpServer
    {
    public:
        typedef std::functiion<void(void)> CallBack;
    private:
        EventLoop* m_pBaseLoop;
        std::shared_ptr<Acceptor> m_spAcceptor;
        std::shared_ptr<EventLoopThreadPool> m_spThreadPool;
         //回调函数
        CallBack m_readHandler;
        CallBack m_writeHandler;
        CallBack m_errorHandler;
        CallBack m_connHandler;

    public:
        TcpServer(EventLoop* loop,uint32_t port);
        ~TcpServer();

        void NewConnectionCallBack(int sockfd,sockaddr* addr,socklen_t len);

        void HandleRead();
        void HandleWrite();
        void HandleError();

        void SetReadHandle(const CallBack &cb)
        {m_readHandler = cb;}

        void SetWriteHandle(const CallBack &cb)
        {m_writeHandler = cb;}

        void SetErrorHandle(const CallBack &cb)
        {m_errorHandler = cb;}
        void SetConnHandle(const CallBack &cb)
        {m_connHandler = cb;}
    };

}




#endif