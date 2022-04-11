#include "EventLoop.h"
#include "../MutexLockGuard.h"
#include <sys/eventfd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include "EpollPoller.h"
#include "../Log.h"
static afa::Logger::ptr logger = LOG_ROOT();
namespace afa
{
    __thread EventLoop* t_loopInThisThread = nullptr;
    int CreateEventfd()
    {
        int evefd = eventfd(0,EFD_NONBLOCK|EFD_CLOEXEC);
        if(evefd<0)
        {
            abort();
        }
        return evefd;
    }
    EventLoop::EventLoop()
    :m_quit(false)
    ,m_threadId(CurrentThread::tid())
    ,m_wakeId(CreateEventfd())
    ,m_IsDoPendingFun(false)
    ,m_spWakeUpChannel(m_wakeId,this)
    ,m_spEpoll(new EpollPoller(this));
    ,m_mutex()
    {
        t_loopInThisThread = this;
        m_spWakeUpChannel->SetReadHandle(std::bind(&EventLoop::HandleRead,this));
        m_spWakeUpChannel->EnableReading();
    }

    EventLoop::~EventLoop()
    {
        close(m_wakeId);
        t_loopInThisThread = nullptr;
    }

    void EventLoop::Loop()
    {
        assertInLoopThread();
        while(!m_quit)
        {
            std::vector<SP_Channel> vctActiveChannel;
            m_spEpoll->Poll(vctActiveChannel);
            int num = vctActiveChannel.size();
            for(int i=0;i<num;i++)
            {
                vctActiveChannel[i]->HandleEvent();
            }
            DoPendingFactor();
        }
    }


    void EventLoop::Quit()
    {
        //此函数由主线程调用，用来使工作线程结束loop循环
        m_quit = true;
        //由于工作线程此时可能阻塞，主线程需要将其唤醒
        if(!IsInLoopThread())
        {
            WakeUp();
        }
    }

    void EventLoop::WakeUp()
    {
        uint64_t one = 1;
        int n = write(m_wakeId,(char*)(&one),sizeof(uint64_t));
        if(n!=sizeof(uint64_t))
        {
            LOG_ERROR(logger)<<"Failed To WakeUp!\n";
        }
    }

    void EventLoop::HandleRead()
    {
        uint64_t one = 1;
        size_t n = read(m_wakeId,&one,sizeof(one));
        if(n!=sizeof(one))
        {
            LOG_ERROR(logger)<<"EventLoop::HandleRead() read"<<n<<"bytes instead of 8!";
        }
    }

    void EventLoop::RunInLoop(const Functor &cb)
    {
        if(IsInLoopThread())
        {
            cb();
        }
        else
        {
            QueueInLoop(std::move(cb));
        }
    }

    void EventLoop::QueueInLoop(const Functor &cb)
    {
        {
            MutexLockGuard lock(&m_mutex);
            m_vctPendingFactor.emplace_back(std::move(cb));
        }
        if(!IsInLoopThread()||!m_IsDoPendingFun)
        {
            WakeUp();
        }
    }

    void EventLoop::UpdateChannel(SP_Channel spChannel)
    {
        m_spEpoll->UpdateChannel(spChannel);
    }

     void EventLoop::RemoveChannel(SP_Channel spChannel)
    {
        m_spEpoll->RemoveChannel(spChannel);
    }

    void EventLoop::DoPendingFactor()
    {
        //当执行此函数时，其它线程可能正在向m_vctPendingFunctor中放入一些待执行的函数
        //如果直接使用m_vctPendingFunctor，可能存在的一个问题是：在该函数取数据过程（for循环中），
        //其它线程放入数据可能造成内存迁移
        //对上述问题，可以在for循环是加锁，但这样锁的粒度将很大（所有pendFun函数执行完才释放锁）
        //因此这里将原m_vctPendingFUnctor中的函数迁移出来，对迁移的目标进行处理，这样在执行pendFun函数期间，其它线程可以继续向原m_vctPendingFunctor进行放入（二者操作的是不同对象了）
        std::vector<Functor> curPendingFunctor;
        m_IsDoPendingFun = true; //避免在执行此函数区间再次对函数唤醒（再次唤醒时没有必要的）
        {
            MutexLockGuard(&m_mutex);
            m_vctPendingFactor.swap(curPendingFunctor);
        }
        int num = curPendingFunctor.size();
        for(int i=0;i<num;i++)
        {
            curPendingFunctor[i]();
        }
        m_IsDoPendingFun = false;
    }

    EventLoop* EventLoop::GetEventLoopOfCurThread()
    {
        return t_loopInThisThread;
    }
}