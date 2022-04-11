#include "Semaphore.h"

namespace afa
{
    Semaphore::Semaphore(int val)
    :val_(val)
    {
        sem_init(&sem_,0,val_);
    }

    Semaphore::~Semaphore()
    {
        sem_destroy(&sem_);
    }

    void Semaphore::Wait()
    {
        sem_wait(&sem_);
    }

    void Semaphore::Post()
    {
        sem_post(&sem_);
    }
}