#ifndef MY_TINY_WEB_LOCK_H
#define MY_TINY_WEB_LOCK_H

#include <pthread.h>
#include <bits/pthreadtypes.h>
class locker
{
private:
    pthread_mutex_t m_lock;

public:
    locker();
    ~locker();

    void Lock();
    void UnLock();

    pthread_mutex_t* Get();

    
};

#endif