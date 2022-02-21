#include "locker.h"
#include <exception>
locker::locker()
{
    if(pthread_mutex_init(&m_lock,NULL)!=0)
    {
        throw std::exception();
    }
}

locker::~locker()
{
    pthread_mutex_unlock(&m_lock);
    pthread_mutex_destroy(&m_lock);
}

void locker::Lock()
{
    pthread_mutex_lock(&m_lock);
}

void locker::UnLock()
{
    pthread_mutex_unlock(&m_lock);
}


pthread_mutex_t* locker::Get()
{
    return &m_lock;
}
