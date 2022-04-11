#include "MutexLock.h"
#include <pthread.h>
namespace afa
{
    MutexLock::MutexLock()
    {
        pthread_mutex_init(&lock_,nullptr);
    }

    MutexLock::~MutexLock()
    {
        pthread_mutex_unlock(&lock_);
        pthread_mutex_destroy(&lock_);
    }
    void MutexLock::Lock()
    {
        pthread_mutex_lock(&lock_);
    }

    void MutexLock::UnLock()
    {
        pthread_mutex_unlock(&lock_);
    }

}