#ifndef MY_TINY_WEB_THREAD_POOL_H
#define MY_TINY_WEB_THREAD_POOL_H

#include <pthread.h>
#include <list>
#include <exception>
#include "../lock/sem.h"
#include "../lock/cond.h"
#include "../lock/locker.h"
#include "../CGImysql/connectionRAII.h"
template <typename T>
class threadpool
{
private:
    int           m_thread_number;//线程池中的线程数
    int           m_max_requests; //请求队列中允许的最大请求数
    pthread_t*    m_pThreadArry;//线程池线程编号的数组
    std::list<T*> m_workQueue;//请求队列
    locker        m_lock;     //保护请求队列，当进行从请求队列中取或者放入请求的时候要加锁
    sem           m_QueueState;//请求队列中的请求数
    int           m_actor_model;//reactor或者proactor,1表示reactor

    connection_pool* m_pConnPool;
    
public:
    threadpool(int actor_model,connection_pool *connPool,int thread_number = 20,int max_request = 20000);
    ~threadpool(){delete m_pThreadArry;};

    bool append(T* request,int state);
    bool append_p(T* request);

private:
    static void* worker(void* arg);   //注释By张阿飞，问题：这里作为线程的函数worker为什么是静态的？
                                      //解答：线程函数的形式是void*(*)(void*),参数只有一个void*，如果不是非静态的，而是一个一般的类成员函数，则会加上一个参数this指针，这样参数列表就不正确了
                                      //作为线程的函数一定是全局的或者类的静态函数
    void run();
};



template <typename T>
threadpool<T>::threadpool(int actor_model,connection_pool *connPool,int thread_number,int max_request)
:m_actor_model(actor_model)
,m_pConnPool(connPool)
,m_thread_number(thread_number)
,m_max_requests(max_request)
{
    if(thread_number<=0||max_request<=0)
    {
        throw std::exception();
    }
    m_pThreadArry = new pthread_t[m_thread_number];
    if(m_pThreadArry==nullptr)
    {
        throw std::exception();
    }

    for(int i=0;i<m_thread_number;i++)
    {
        if(pthread_create(&m_pThreadArry[i],NULL,worker,this)!=0)
        {
            delete []m_pThreadArry;
            throw std::exception();
        }
        if(pthread_detach(m_pThreadArry[i]))
        {
            delete []m_pThreadArry;
            throw std::exception();
        }
    }
}


template<typename T>
bool threadpool<T>::append(T* request,int state)
{
    m_lock.Lock();
    if(m_workQueue.size()>=m_max_requests)
    {
        m_lock.UnLock();
        return false;
    }

    request->m_state = state;
    m_workQueue.push_back(request);
    m_lock.UnLock();
    m_QueueState.Post();
    return true;

}

template<typename T>
bool threadpool<T>::append_p(T* request)
{
    m_lock.Lock();
    if(m_workQueue.size()>=m_max_requests)
    {
        m_lock.UnLock();
        return false;
    }

    //request->m_state = request->m_state;
    m_workQueue.push_back(request);
    m_lock.UnLock();
    m_QueueState.Post();
    return true;
}

template<typename T>
void* threadpool<T>::worker(void* arg)
{
    threadpool* pool = (threadpool*)arg;
    pool->run();
    return pool;
}

template<typename T>
void threadpool<T>::run()
{
    while(true)
    {
        m_QueueState.Wait();
        m_lock.Lock();//这里加锁是因为要保护任务队列：任务队列是多个线程共享的，但是使用的是stl的list，它不是线程安全的
        if(m_workQueue.empty())
        {
            m_lock.UnLock();
            continue;
        }
        T* request = m_workQueue.front();
        m_workQueue.pop_front();
        m_lock.UnLock();
        if(request==nullptr)
        {
            continue;
        }
        if(m_actor_model==1)
        {
            if(0==request->m_state)//请求的读写状态：0为可读，1为可写
            {
                //可读事件
                if(request->read_once())
                {
                    request->m_improv=1;
                    connectionRAII mysqlConn(&request->mysql,m_pConnPool);//RAII机制，构造时，从mysql连接池中取出一个连接给request->mysql,执行完process后，表示对请求的响应完成，mysqlConn析构时，自动将连接再放回连接池
                    request->process();
                }
                else
                {
                    request->m_improv = 1;
                    request->m_time_flag = 1;
                }
            }
            else
            {
                //可写事件
                if(request->write())
                {
                    request->m_improv = 1;
                }
                else
                {
                    request->m_improv = 1;
                    request->m_time_flag = 1;
                }
            }
        }
        else
        {
            //proactor模式，数据已经读写到缓冲去，工作线程直接进行逻辑处理
            connectionRAII mysqlConn(&request->mysql,m_pConnPool);
            request->process();
        }
    }
}

#endif