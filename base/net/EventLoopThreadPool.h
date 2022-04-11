#ifndef EVENT_LOOP_THREAD_POOL_H
#define EVENT_LOOP_THREAD_POOL_H
#include "EventLoop.h"
#include "EventLoopThread.h"
#include <vector>
#include <memory>
#include <bits/shared_ptr.h>
namespace afa
{
    class EventLoopThreadPool
    {
    public:

    private:
        EventLoop* pBaseLoop_;
        int numThreads_;
        int next_;
        bool started_;
        std::vector<std::shared_ptr<EventLoopThread> > threads_;
        std::vector<EventLoop*> loops_;

    public:
        EventLoopThreadPool(EventLoop* loop,int numThread=10);
        ~EventLoopThreadPool();

        void Start();

        EventLoop* GetNextLoop();

    };
}




#endif