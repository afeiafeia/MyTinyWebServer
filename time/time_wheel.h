//使用基于排序链表的定时器存在的问题：每次添加定时器要遍历链表，效率低，且随着定时器数目的增多，效率进一步降低

//时间轮采用哈希的思想，将定时器散列到不同的链表上



#ifndef MY_TINY_WEB_TIME_WHEEL_H
#define MY_TINY_WEB_TIME_WHEEL_H

#define BUFFSIZE 64
#include <netinet/in.h>
class util_time;
struct client_data
{
    sockaddr_in address;  
    int         sockfd;
    char        buff[BUFFSIZE];
    util_time*  time;
};

class util_time
{
public:
    util_time* prev;
    util_time* next;
    int m_rotation;    //该定时器在转多少圈后生效
    int m_time_slot;   //属于时间轮上的哪个槽
    void (*cb_func)(client_data* idata); //回调函数指针
    client_data* user_data;

    time_t    expire;
public:
    util_time()
    :prev(nullptr)
    ,next(nullptr)
    ,m_rotation(0)
    ,m_time_slot(0)
    {

    }
    util_time(int rotation,int slot)
    :prev(nullptr)
    ,next(nullptr)
    ,m_rotation(rotation)
    ,m_time_slot(slot)
    {

    }
    ~util_time()
    {}
};
class time_wheel
{
private:
    static const int N  = 30; //时间轮上的槽数
    static const int SI = 1; //槽的间隔时间
    util_time* slots[N];     //槽上的链表
    int m_cur_slot;            //当前槽

public:
    time_wheel();
    ~time_wheel();

    util_time* add_time(util_time* ipAdd_Timer);

    void del_time(util_time* ipDel_Timer);

    void adjust_time(util_time* ipAdj_Timer);

    void tick();




};

#endif