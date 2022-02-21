#ifndef MY_TINY_WEB_COND_H
#define MY_TINY_WEB_COND_H
#include <pthread.h>

class cond
{
private:
    pthread_cond_t m_cond;

public: 
    cond();
    ~cond();

    bool Wait(pthread_mutex_t* mutex);

    bool TimeWait(pthread_mutex_t* mutex,struct timespec time);

    bool Signal();

    bool Broadcast();



};


#endif