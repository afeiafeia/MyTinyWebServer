#include "rw_lock.h"
#include <asm-generic/errno-base.h>
pthread_rwlock_t::pthread_rwlock_t()
:m_mutex(PTHREAD_MUTEX_INITIALIZER)
,m_readCond(PTHREAD_COND_INITIALIZER)
,m_writerCond(PTHREAD_COND_INITIALIZER)
,m_magic(1)
,m_numWaitReader(0)
,m_numWaitWriter(0)
,m_refCount(0)
{
    //int errorno = 0;
    //errorno =pthread_rwlock_init();
}


int pthread_rwlock_t::pthread_rwlock_init()
{
    int errorno = 0;
    errorno = pthread_mutex_init(&m_mutex,NULL);
    if(errorno!=0)
    {
        pthread_mutex_destroy(&m_mutex);
    }

    errorno = pthread_cond_init(&m_readCond,NULL);
    if(errorno!=0)
    {
        pthread_cond_destroy(&m_readCond);
    }

    errorno = pthread_cond_init(&m_writerCond,NULL);
    if(errorno!=0)
    {
        pthread_cond_destroy(&m_writerCond);
    }
    return 0;

}
int pthread_rwlock_t::pthread_rwlock_rdlock()
{
    int errorno = 0;
    errorno = pthread_mutex_lock(&m_mutex);
    if(errorno!=0)
    return errorno;
    while(m_refCount<0||m_numWaitWriter>0)
    {
        m_numWaitReader++;
        pthread_cond_wait(&m_readCond,&m_mutex);
        m_numWaitReader--;
    }

    m_refCount++;
    errorno = pthread_mutex_unlock(&m_mutex);

    return errorno;
}

int pthread_rwlock_t::pthread_rwlock_wrlock()
{
    int errorno = 0;
    errorno = pthread_mutex_lock(&m_mutex);
    if(errorno!=0)
    return errorno;

    while(m_refCount!=0)
    {
        m_numWaitWriter++;
        errorno = pthread_cond_wait(&m_writerCond,&m_mutex);
        m_numWaitWriter--;
        if(errorno!=0)
            break;
    }
    if(errorno==0)
        m_refCount = -1;

    pthread_mutex_unlock(&m_mutex);
    return 0;
}

int pthread_rwlock_t::pthread_rwlock_tryrdlock()
{
    int errorno = 0;
    errorno = pthread_mutex_lock(&m_mutex);
    if(errorno!=0)
    return errorno;
    if(m_refCount<0||m_numWaitWriter>0)
        errorno = EBUSY;
    else
        m_refCount++;

    pthread_mutex_unlock(&m_mutex);
    return errorno;

}

int pthread_rwlock_t::pthread_rwlock_trywrlock()
{
    int errorno = 0;
    errorno = pthread_mutex_lock(&m_mutex);
    if(errorno!=0)
    return errorno;

    if(m_refCount!=0)
        errorno = EBUSY;
    else   
        m_refCount=-1;

    pthread_mutex_unlock(&m_mutex);
    return 0;
}

int pthread_rwlock_t::pthread_rwlock_unlock()
{
    int errorno = 0;
    errorno = pthread_mutex_lock(&m_mutex);
    if(errorno!=0)
    return errorno;

    if(m_refCount>0)
        m_refCount--;
    else if(m_refCount==-1)
        m_refCount = 0;

    if(m_numWaitWriter>0&&m_refCount==0)
    {
        pthread_cond_signal(&m_writerCond);
    }
    else if(m_numWaitReader>0)
    {
        pthread_cond_broadcast(&m_readCond);
    }
    errorno = pthread_mutex_unlock(&m_mutex);
    return errorno;

}

int pthread_rwlock_t::pthread_rwlock_destroy()
{
    int errorno = 0;
    errorno = pthread_mutex_lock(&m_mutex);
    if(errorno!=0)
    return errorno;
    if(m_refCount!=0
    ||m_numWaitReader!=0
    ||m_numWaitWriter!=0)
    {
        return EBUSY;
    }
    errorno = pthread_mutex_destroy(&m_mutex);
    errorno = pthread_cond_destroy(&m_readCond);
    errorno = pthread_cond_destroy(&m_writerCond);

    m_numWaitReader=0;
    m_numWaitWriter=0;
    m_refCount=0;
    errorno = pthread_mutex_unlock(&m_mutex);
    return errorno;
}