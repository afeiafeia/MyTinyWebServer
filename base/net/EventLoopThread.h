#ifndef EVENT_LOOP_THREAD_H
#define EVENT_LOOP_THREAD_H
#include <functional>
#include "EventLoop.h"
#include "../Thread.h"
#include "../MutexLock.h"
#include "../Condition.h"
namespace afa
{
    class EventLoopThread
    {
    private:
        typedef std::function<void()> ThreadFun;
        EventLoop* loop_;
        Thread thread_;

        MutexLock mutex_;
        Condition cond_;

    public:
        EventLoopThread();
        ~EventLoopThread();

        EventLoop* StartLoop();

        void ThreadFunc();
    };
}



#endif