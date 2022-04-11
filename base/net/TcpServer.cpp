#include "TcpServer.h"
#include "Acceptor.h"
#include "EventLoopThreadPool.h"
namespace afa
{
    TcpServer::TcpServer(EventLoop* loop,uint32_t port)
    :m_pBaseLoop(loop)
    ,m_spAcceptor(new Acceptor(port,loop))
    ,m_spThreadPool(new EventLoopThreadPool(loop));
    {
        m_spThreadPool->Start();
        m_spAcceptor->SetNewConnectionCB(std::bind(&TcpServer::NewConnectionCallBack,this,_1,_2,_3));
    }
    TcpServer::~TcpServer()
    {

    }


    void TcpServer::NewConnectionCallBack(int sockfd,sockaddr* addr,socklen_t len)
    {
        EventLoop* curLoop = m_spThreadPool->GetNextLoop();
        SP_Channel connChannel(new Channel(curLoop,sockfd));

        connChannel->SetReadHandle(m_readHandler);
        connChannel->SetWriteHandle(m_writeHandler);
        connChannel->SetErrorHandle(m_errorHandler);

        curLoop->RunInLoop(std::bind(&Channel::EnableReading,connChannel));
    }
}