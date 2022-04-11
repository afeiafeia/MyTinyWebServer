#ifndef CHANNEL_H
#define CHANNEL_H
#include <functional>
#include <sys/epoll.h>
#include <memory>

namespace afa
{
    class EventLoop;

    class Channel:public std::enable_shared_from_this<Channel>
    {
    public:
        typedef std::function<void()> CallBack;

    private:
        int        m_fd;
        EventLoop* m_loop;     //所属的事件循环
        __uint32_t m_events;   //监视事件
        __uint32_t m_revents;

        int m_index; //用于标记该Channel对应的套接字是否已经注册到了epoll中或者从其中删除

        static const int s_readEvent;
        static const int s_writeEvent;
        static const int s_errorEvent;

        //回调函数
        CallBack m_readHandler;
        CallBack m_writeHandler;
        CallBack m_errorHandler;
        CallBack m_connHandler;
    public:
        Channel(int fd,EventLoop* loop);

        ~Channel();

        /**
         * @brief  注册可读事件
         * @author afei
         * @date   2022-03-27
         */
        void EnableReading()
        {
            m_events|s_readEvent;
            Update();
        }

        /**
         * @brief  取消对可读事件的监视
         * @author afei
         * @date   2022-04-10
         */
        void DisableReading()
        {
            m_events&~s_readEvent;
            Update();
        }

        /**
         * @brief  注册可写事件
         * @author afei
         * @date   2022-03-27
         */
        void EnableWriting()
        {
            m_events|s_writeEvent;
            Update();
        }
        /**
         * @brief  取消对可写事件的监视
         * @author afei
         * @date   2022-04-10
         */
        void DisableWriting()
        {
            m_events&~s_writeEvent;
            Update();
        }

        void SetReadHandle(CallBack readHandle)
        {
            m_readHandler = readHandle;
        }

        void SetWriteHandler(CallBack writeHandle)
        {
            m_writeHandler = writeHandle;
        }

        void SetErrorHandler(CallBack errorHandler)
        {
            m_errorHandler = errorHandler;
        }

        void SetConnectHandler(CallBack connHandler)
        {
            m_connHandler = connHandler;
        }

        void ReadHandler();
        void WriteHandler();
        void ErrorHandler();
        void ConnectHandler();

        /**
         * @brief  事件处理函数
         * @author afei
         * @date   2022-03-27
         */
        void HandleEvent();

        void SetEvents(__int32_t event)
        {
            m_events = event;
        }
        __int32_t GetEvents(){return m_events;}

        int Getfd()
        {
            return m_fd;
        }

        int GetIndex()
        {
            return m_index;
        }

        void SetIndex(int index)
        {
            m_index = index;
        }

        void Remove();

    private:
        /**
         * @brief  更新所监视的事件
         * @author afei
         * @date   2022-03-27
         */
        void Update();








        


    };

    typedef std::shared_ptr<Channel> SP_Channel;
}




#endif
