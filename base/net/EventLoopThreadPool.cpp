#include "EventLoopThreadPool.h"

namespace afa
{
    EventLoopThreadPool::EventLoopThreadPool(EventLoop* loop,int numThread)
    :pBaseLoop_(loop)
    ,numThreads_(numThread)
    ,next_(0)
    ,started_(false)
    {

    }

    EventLoopThreadPool::~EventLoopThreadPool()
    {

    }

    void EventLoopThreadPool::Start()
    {
        pBaseLoop_->assertInLoopThread();//保证都在主线程调用该函数
        started_ = true;
        for(int i=0;i<numThreads_;i++)
        {
            std::shared_ptr<EventLoopThread> cur(new EventLoopThread());
            threads_.push_back(cur);
            loops_.push_back(cur->StartLoop());
        }
    }

    EventLoop* EventLoopThreadPool::GetNextLoop()
    {
        pBaseLoop_->assertInLoopThread();//保证都在主线程调用该函数
        EventLoop* curLoop = pBaseLoop_;
        if(!loops_.empty())
        {
            curLoop = loops_[next_];
            next_ = (next_+1)%numThreads_;
        }
        return curLoop;
    }

}