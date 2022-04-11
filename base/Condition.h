#ifndef CONDITION_H
#define CONDITION_H
#include <bits/pthreadtypes.h>
#include "noncopyable.h"
#include "MutexLock.h"
#include <pthread.h>
namespace afa
{
    class Condition:public noncopyable
    {
    private:
        pthread_cond_t cond_;
        MutexLock &mutex_;//注意是引用
    public:
        Condition(MutexLock& mutex)
        :mutex_(mutex)
        {
            pthread_cond_init(&cond_,nullptr);
        }
        ~Condition()
        {
            pthread_cond_destroy(&cond_);
        }

        void Wait()
        {
            pthread_cond_wait(&cond_,mutex_.get());
        }
        void Broadcast()
        {
            pthread_cond_broadcast(&cond_);
        }
        void Signal()
        {
            pthread_cond_signal(&cond_);
        }
    };
}

#endif