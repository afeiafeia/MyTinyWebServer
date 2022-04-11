#ifndef MUTEX_LOCK_GUARD_H
#define MUTEX_LOCK_GUARD_H
#include "noncopyable.h"
#include "MutexLock.h"
namespace afa
{
    class MutexLockGuard:public noncopyable
    {
    private:
        MutexLock* mutexlock_;
    public:
        MutexLockGuard(MutexLock* mutex)
        :mutexlock_(mutex)
        {
            mutexlock_->Lock();
        }
        ~MutexLockGuard()
        {
            mutexlock_->UnLock();
        }
    };
}
#endif