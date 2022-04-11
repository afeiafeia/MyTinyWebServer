//以时间堆方式实现定时器
#ifndef MY_TINY_WEB_TIME_GEAP_H
#define MY_TINY_WEB_TIME_GEAP_H

#define BUFFSIZE 64
#include <netinet/in.h>
#include <ctime>
#include <vector>
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

    time_t m_expire;//失效时间


public:

    util_time(int delayTime)
    {
        m_expire = time(NULL)+delayTime;
    }
    void (*cb_func)(client_data* ipdata);
};

class time_heap
{
private:
    //堆数组
    std::vector<util_time*> m_vctTimer;


public:
    time_heap(int capacity);

    void add_time(util_time* ipAddTime);

    void del_time();

    void tick();

};









#endif