#ifndef MY_TINY_WEB_SEM_H
#define MY_TINY_WEB_SEM_H

#include <semaphore.h>
class sem
{
private:
    sem_t m_sem;
public:
    sem();
    sem(int num);

    ~sem();

    //测试信号量的值，如果小于等于0，调用线程阻塞（是一个原子操作）
    void Wait();
    //先将信号量的值减去1，如果此时信号量的值大于0，将唤醒阻塞在这个信号量上的其中一个线程
    void Post();

};

#endif