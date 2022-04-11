#include "EventLoopThread.h"
#include "../MutexLockGuard.h"
namespace afa
{
    EventLoopThread::EventLoopThread()
    :loop_(nullptr)
    ,thread_(std::bind(&EventLoopThread::ThreadFunc,this),"EventLoopThread")
    ,mutex_()
    ,cond_(mutex_)
    {

    }

    EventLoopThread::~EventLoopThread()
    {
        if(loop_!=nullptr)
        {
            thread_.Join();
        }
    }

    //此函数由主线程调用
    EventLoop* EventLoopThread::StartLoop()
    {
        thread_.Start();
        {
            MutexLockGuard lock(&mutex_);
            while(loop_==nullptr)
            {
                //一直到线程ThreadFunc真正跑起来
                cond_.Wait();
            }

        }
        return loop_;
    }

    //工作线程
    void EventLoopThread::ThreadFunc()
    {
        EventLoop loop;
        {
            MutexLockGuard lock(&mutex_);
            loop_ = &loop;
            cond_.Signal();
        }
        loop_->Loop();
        
        loop_=nullptr;
    }

}