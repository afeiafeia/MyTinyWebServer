#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include "noncopyable.h"
#include<semaphore.h>

namespace afa
{
    class Semaphore:public noncopyable
    {
    private:
        int val_;
        sem_t sem_;
    public:
        Semaphore(int val=1);
        ~Semaphore();

        void Wait();
        void Post();


    };
}


#endif