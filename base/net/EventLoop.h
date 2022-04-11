#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include "../CurrentThread.h"
#include "../MutexLock.h"

#include <sys/wait.h>
#include <functional>
#include <vector>
#include <assert.h>
#include <memory>
namespace afa
{
    class Channel;
    class EpollPoller;
    
    class EventLoop
    {
    public:
        typedef std::function<void()> Functor;
        typedef std::shared_ptr<Channel> SP_Channel;
        EventLoop();
        ~EventLoop();

        /**
         * @brief  事件循环
         * @author afei
         * @date   2022-04-06
         */
        void Loop();

        /**
         * @brief  使事件循环终止
         * @author afei
         * @date   2022-04-06
         */
        void Quit();

        /**
         * @brief  唤醒阻塞在io复用上的线程
         * @author afei
         * @date   2022-04-06
         */
        void WakeUp();

        /**
         * @brief  判断执行IsInLoopThread的线程是否为创建该loop的线程
         * @author afei
         * @date   2022-03-27
         * @return true 
         * @return false 
         */
        bool IsInLoopThread() {return m_threadId==CurrentThread::tid();}

        void assertInLoopThread(){assert(IsInLoopThread());}
        
        void RunInLoop(const Functor &cb);

        void QueueInLoop(const Functor &cb);

        void UpdateChannel(SP_Channel spChannel);
        void RemoveChannel(SP_Channel spChannel);

        void DoPendingFactor();

        void HandleRead();

        static EventLoop* GetEventLoopOfCurThread();
    private:
        bool                         m_quit;
        const pid_t                  m_threadId;//线程id
        int                          m_wakeId;  //事件描述符，用于唤醒工作线程（通过向描述符写入数据的方式）
        bool                         m_isDoPendingFun;//是否正在执行DoPendingFunctor
        SP_Channel                   m_spWakeUpChannel;
        std::vector<Functor>         m_vctPendingFactor;
        std::unique_ptr<EpollPoller> m_spEpoll;
        MutexLock                    m_mutex;


    };
}

#endif