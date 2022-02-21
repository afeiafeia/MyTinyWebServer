#include "cond.h"
#include <exception>
cond::cond()
{
    if(pthread_cond_init(&m_cond,NULL)!=0)
    {
        throw std::exception();
    };
}

cond::~cond()
{
    pthread_cond_destroy(&m_cond);
}

bool cond::Wait(pthread_mutex_t* mutex)
{
    return pthread_cond_wait(&m_cond,mutex);
}

bool cond::TimeWait(pthread_mutex_t* mutex,struct timespec time)
{
    return pthread_cond_timedwait(&m_cond,mutex,&time);
}

bool cond::Signal()
{
    return pthread_cond_signal(&m_cond);
}

bool cond::Broadcast()
{
    return pthread_cond_broadcast(&m_cond);
}
