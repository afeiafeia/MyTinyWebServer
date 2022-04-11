#ifndef THREAD_H
#define THREAD_H
#include "noncopyable.h"
#include "Semaphore.h"
#include <pthread.h>
#include <functional>
namespace afa
{
    //extern double afaaa;

    class Thread:public noncopyable
    {
    public:
        typedef std::function<void()> ThreadFun;
    private:
        bool started_;
        bool joined_;         
        pthread_t pthreadID_;
        pid_t tid_;
        std::string name_;
        ThreadFun func_;
        Semaphore sem_;
    public:
        Thread(const ThreadFun& fun,const std::string &name = std::string());
        ~Thread();
        void Start();
        std::string GetName(){return name_;}

        void Join();


    };
}



#endif