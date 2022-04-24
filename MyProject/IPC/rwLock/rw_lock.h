#ifndef PTHREAD_RWLOCK_T_H
#define PTHREAD_RWLOCK_T_H

#include<bits/pthreadtypes.h>
#include <pthread.h>

#define RW_MAGIC 0x19283726

#define PTHREAD_RWLOCK_INITIALIZER {PTHREAD_MUTEX_INITIALIZER, \
PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER,RW_MAGIC,0,0,0}

class pthread_rwlock_t
{
private:
    pthread_mutex_t  m_mutex;
    pthread_cond_t   m_readCond;
    pthread_cond_t   m_writerCond;

    int m_magic;
    int m_numWaitReader;
    int m_numWaitWriter;
    int m_refCount;

public:

    pthread_rwlock_t();
    ~pthread_rwlock_t();

   
    int pthread_rwlock_rdlock();
    int pthread_rwlock_wrlock();
    int pthread_rwlock_tryrdlock();
    int pthread_rwlock_trywrlock();
    int pthread_rwlock_unlock();
    
    //初始化
    int pthread_rwlock_init();
    //释放
    int pthread_rwlock_destroy();
};

#endif

