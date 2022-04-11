#include "Acceptor.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <assert.h>
#include <unistd.h>
#include "../Log.h"
static afa::Logger::ptr logger = LOG_ROOT();
namespace afa
{
    Acceptor::Acceptor(int port,EventLoop* loop)
    :m_baseLoop(loop)
    ,m_listenfd(socket(PF_INET,SOCK_STREAM,0))
    ,m_port(port)
    ,m_channel(new Channel(m_listenfd,m_baseLoop))
    {
        m_channel->SetReadHandle(std::bind(&Acceptor::NewAccept,this));
    }
    Acceptor::~Acceptor()
    {

    }
    void Acceptor::Listen()
    {
        struct sockaddr_in address;
        bzero(&address,sizeof(sockaddr_in));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_ANY);
        address.sin_port = m_port;
        int ret = bind(m_listenfd,(struct sockaddr*)(&address),sizeof(address));
        assert(ret>=0);//如果为真继续执行，如果为假程序退出
        ret = listen(m_listenfd,100);
        assert(ret>=0);

        m_channel->EnableReading();
    }

    void Acceptor::NewAccept()
    {
        struct sockaddr_in srcDsct;
        socklen_t length = static_cast<socklen_t>(sizeof(srcDsct));
        //非阻塞读取：一般的accept没有最后一个选项，新函数accept4有此参数
        int connfd = accept4(m_listenfd,(struct sockaddr*)&srcDsct,&length,SOCK_NONBLOCK);
        if(connfd>0)
        {
            //如果设置了回调函数，执行回调函数，否则关闭连接套接字不予处理
            if(m_newConnectionCB)
            {
                m_newConnectionCB(connfd,(struct sockaddr*)&srcDsct,length);
            }
            else
            {
                close(connfd);
            }
        }
        else
        {
            LOG_ERROR(logger)<<"Failed To Accept!\n";
        }

        
    }

}