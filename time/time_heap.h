//以时间堆方式实现定时器
#ifndef MY_TINY_WEB_TIME_GEAP_H
#define MY_TINY_WEB_TIME_GEAP_H

#define BUFFSIZE 64
#include <netinet/in.h>
#include <ctime>
#include "heap.h"
class util_time;
struct client_data
{
    sockaddr_in  address;
    int sockfd;
    char buff[BUFFSIZE];
    util_time* timer;
};

class util_time
{
public:
    time_t       m_CurTime;
    client_data* m_pUser_data;

public:

    bool operator<(const util_time& rhs)
    {
        return m_CurTime<rhs.m_CurTime;
    }
    bool operator>(const util_time& rhs)
    {
        return m_CurTime>rhs.m_CurTime;
    }
};

class time_heap
{
private:
    mystl_heap<util_time> time_heap;

    void add_timer(util_time* ipAddTime);

    void del_timer(util_time* ipDelTime);

    void tick();
};

#endif