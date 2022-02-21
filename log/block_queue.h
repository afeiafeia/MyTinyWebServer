/*************************************************************
*循环数组实现的阻塞队列，m_back = (m_back + 1) % m_max_size;  
*线程安全，每个操作前都要先加互斥锁，操作完后，再解锁
**************************************************************/

#ifndef BLOCK_QUEUE_H
#define BLOCK_QUEUE_H

#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "../lock/locker.h"
#include "../lock/cond.h"
#include "../lock/sem.h"
using namespace std;

template <class T>
class block_queue
{

public:

    typedef block_queue<T>* pointer;
public:
    block_queue(int max_size = 1000)
    {
        if (max_size <= 0)
        {
            exit(-1);
        }

        m_max_size = max_size;
        m_array = new T[max_size];
        m_size = 0;
        m_front = -1;
        m_back = -1;
    }

    void clear()
    {
        m_mutex.Lock();
        m_size = 0;
        m_front = -1;
        m_back = -1;
        m_mutex.UnLock();
    }

    ~block_queue()
    {
        m_mutex.Lock();
        if (m_array != NULL)
            delete [] m_array;

        m_mutex.UnLock();
    }
    //判断队列是否满了
    bool full() 
    {
        m_mutex.Lock();
        if (m_size >= m_max_size)
        {

            m_mutex.UnLock();
            return true;
        }
        m_mutex.UnLock();
        return false;
    }
    //判断队列是否为空
    bool empty() 
    {
        m_mutex.Lock();
        if (0 == m_size)
        {
            m_mutex.UnLock();
            return true;
        }
        m_mutex.UnLock();
        return false;
    }
    //返回队首元素
    bool front(T &value) 
    {
        m_mutex.Lock();
        if (0 == m_size)
        {
            m_mutex.UnLock();
            return false;
        }
        value = m_array[m_front];
        m_mutex.UnLock();
        return true;
    }
    //返回队尾元素
    bool back(T &value) 
    {
        m_mutex.Lock();
        if (0 == m_size)
        {
            m_mutex.UnLock();
            return false;
        }
        value = m_array[m_back];
        m_mutex.UnLock();
        return true;
    }

    int size() 
    {
        int tmp = 0;

        m_mutex.Lock();
        tmp = m_size;

        m_mutex.UnLock();
        return tmp;
    }

    int max_size()
    {
        int tmp = 0;

        m_mutex.Lock();
        tmp = m_max_size;

        m_mutex.UnLock();
        return tmp;
    }
    //往队列添加元素，需要将所有使用队列的线程先唤醒
    //当有元素push进队列,相当于生产者生产了一个元素
    //若当前没有线程等待条件变量,则唤醒无意义
    bool push(const T &item)
    {

        m_mutex.Lock();
        if (m_size >= m_max_size)
        {

            m_cond.Broadcast();
            m_mutex.UnLock();
            return false;
        }

        m_back = (m_back + 1) % m_max_size;
        m_array[m_back] = item;

        m_size++;

        m_cond.Broadcast();
        m_mutex.UnLock();
        return true;
    }
    //pop时,如果当前队列没有元素,将会等待条件变量
    bool pop(T &item)
    {

        m_mutex.Lock();
        while (m_size <= 0)
        {
            //此处使用循环是因为：wait使得调用进程阻塞，同时释放锁；之后，当该进程被唤醒时，会继续从此处执行，此时，条件仍然为真m_size仍小于0，
            //如果是if语句，将之后后续步骤进行消费，就会出现问题:没有资源可以消费但是却执行消费
            if (!m_cond.Wait(m_mutex.Get()))
            {
                m_mutex.UnLock();
                return false;
            }
        }

        m_front = (m_front + 1) % m_max_size;
        item = m_array[m_front];
        m_size--;
        m_mutex.UnLock();
        return true;
    }

    //增加了超时处理
    bool pop(T &item, int ms_timeout)
    {
        struct timespec t = {0, 0};
        struct timeval now = {0, 0};
        gettimeofday(&now, NULL);
        m_mutex.Lock();
        if (m_size <= 0)
        {
            t.tv_sec = now.tv_sec + ms_timeout / 1000;
            t.tv_nsec = (ms_timeout % 1000) * 1000;
            if (!m_cond.TimeWait(m_mutex.Get(), t))
            {
                m_mutex.UnLock();
                return false;
            }
        }

        if (m_size <= 0)
        {
            m_mutex.UnLock();
            return false;
        }

        m_front = (m_front + 1) % m_max_size;
        item = m_array[m_front];
        m_size--;
        m_mutex.UnLock();
        return true;
    }

private:
    locker m_mutex;
    cond m_cond;

    T *m_array;
    int m_size;
    int m_max_size;
    int m_front;
    int m_back;
};

#endif
