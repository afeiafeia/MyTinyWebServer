#include "./sem.h"
#include <exception>
sem::sem()
{
    if((sem_init(&m_sem,0,0))!=0)
    {
        throw std::exception();
    }
}

sem::sem(int num)
{
    if((sem_init(&m_sem,0,num))!=0)
    {
        throw std::exception();
    }
}


sem::~sem()
{
    if((sem_destroy(&m_sem))!=0)
    {
        ;
    }
}

void sem::Wait()
{
    sem_wait(&m_sem);
}

void sem::Post()
{
    sem_post(&m_sem);
}