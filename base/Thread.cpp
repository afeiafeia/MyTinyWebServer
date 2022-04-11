#include "Thread.h"
#include "CurrentThread.h"
#include <assert.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

namespace afa
{
    static double afaaa = 1.0;
    namespace CurrentThread
    {
        int tid();
    }
    struct ThreadData
    {
        typedef Thread::ThreadFun ThreadFun;
        std::string name_;
        ThreadFun  func_;
        pid_t* tid_;
        Semaphore* sem_;

        ThreadData(const ThreadFun& fun,const std::string &na,pid_t* tid,Semaphore* sem)
        :func_(fun)
        ,name_(na)
        ,tid_(tid)
        ,sem_(sem)
        {

        }

        void RunInThread()
        {
            *tid_ = CurrentThread::tid();
            CurrentThread::t_threadName = name_.empty()?"Thread":name_.c_str();
            sem_->Post();//此处调用Post是为了：保证线程函数RunInThread先运行起来，然后调用post唤醒主线程，保证主线程获取该线程时，该线程已经运行起来
            func_();
            CurrentThread::t_threadName = "Finished";
        }
    };
    namespace CurrentThread
    {
        __thread int  t_cachedTid;          //线程id
        __thread char t_tidString[32];      //id的字符数组（配合长度使用）
        __thread int  t_tidStringLen;       //id长度（配合字符数组使用）
        __thread const char* t_threadName = "Default"; //线程名称

        pid_t getpid()
        {
            return static_cast<pid_t>(::syscall(SYS_gettid));
        }
        void cacheTid()
        {
            if(t_cachedTid==0)
            {
                t_cachedTid = getpid();
                t_tidStringLen = snprintf(t_tidString,sizeof(t_tidString),"%5d",t_cachedTid);
            }
        }
    };

   

    void* StartThread(void* data)
    {
        ThreadData* pData = static_cast<ThreadData*>(data);
        if(pData==nullptr)
        {
            return nullptr;
        }
        pData->RunInThread();
        //线程主逻辑结束后，data资源由当前线程释放而不是主线程
        delete pData;
        pData = nullptr;
        return nullptr;
    }

    Thread::Thread(const ThreadFun& fun,const std::string &name)
    :started_(false)
    ,joined_(false)
    ,pthreadID_(0)
    ,tid_(0)
    ,name_(name)
    ,func_(fun)
    ,sem_(0)
    {
        if(name_.empty())
        {
            name_ = "Thread";
        }
    }
    Thread::~Thread()
    {
        if(started_&&!joined_)
        {

            //调用线程将不等待pthreadID_的线程退出后再退出
            //对同一个线程不能即调用pthread_detach又调用pthread_join，二者只能调用一个
            pthread_detach(pthreadID_);
        }
    }

    void Thread::Start()
    {
        assert(!started_);
        started_ = true;
        //data资源应该在线程StartThread中释放，不在当前主线程释放；因为存在可能情况：如果主线程释放，主线程可能先运行后续内容，导致工作线程还没有使用data，data就被释放
        ThreadData* pData = new ThreadData(func_,name_,&tid_,&sem_);
        //pthread_create  成功时返回0，出错返回错误编号（正值）
        if(pthread_create(&pthreadID_,NULL,StartThread,pData))
        {
            //线程创建失败
            started_ = false;
            delete pData;
        }
        else
        {
            pthread_detach(pthreadID_);
            //线程创建成功
            sem_.Wait();//主线程要先阻塞，等子线程StartThread运行起来后再返回，防止主线程后面使用子线程时，子线程还没有运行起来
        }

    }

    void Thread::Join()
    {
        //int pthread_join(pthread_t threadId,void * * ptr);
        //调用pthread_join的线程将一直阻塞，直到threadId的线程退出
        if(!joined_)
        joined_ = true;
        pthread_join(pthreadID_,NULL);
    }
}