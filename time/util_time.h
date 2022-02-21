#ifndef MY_TINY_WEB_TIME_H
#define MY_TINY_WEB_TIME_H

#include <time.h>
#include "netinet/in.h"
#include <stdio.h>
#define BUFFER_SIZE 64
class util_time;

struct client_data
{
    struct sockaddr_in address;
    int                sockfd;
    char               buff[BUFFER_SIZE];
    util_time*         time;
};

//定时器链表的节点（一个连接对应的定时器）
class util_time
{
public:
    client_data* user_data;
    //util_time* prev;
    util_time* next;
    time_t expire;

    public:
    util_time(){};
    void (*cb_func)(client_data* ipdata);

};


class sort_time_list
{
private:
    util_time* head;
    util_time* tail;
public:
    sort_time_list(){
        //tail = head = new util_time();
        //head->expire = 0;
        tail = head = nullptr;

    };
    ~sort_time_list()
    {
        util_time* tmpHead = head;
        while(tmpHead)
        {
            delete tmpHead;
            tmpHead = head->next;
            head = head->next;
        }
    }

    void add_time(util_time* ipCurTime)
    {
        if(!ipCurTime)
        {
            return ;
        }
        if(!head)
        {
            tail = head = ipCurTime;
            ipCurTime->next = nullptr;
            return;
        }
        util_time* tmp = head;
        if(head->expire>ipCurTime->expire)
        {
            ipCurTime->next = head;
            head = ipCurTime;
            return ;
        }
        while(tmp&&tmp->next&&ipCurTime->expire>tmp->next->expire)
        {
            tmp = tmp->next;
            //ipCurTime->next = head;
            //head->prev = ipCurTime;
            //head = ipCurTime;
            //return;
        }

        if(tmp->next)
        {
            //if(tmp==head)
            //{
            //    //head->prev = ipCurTime;
            //    ipCurTime->next = head;
            //    //ipCurTime->prev = nullptr;
            //    head = ipCurTime;
            //}
            //else

            {
                //tmp->prev->next = ipCurTime;
                //ipCurTime->prev = tmp->prev;
                ipCurTime->next = tmp->next;
                tmp->next = ipCurTime;
                //ipCurTime->next = tmp;
                //tmp->prev = ipCurTime;
            }
        }
        else
        {
            ipCurTime->next=nullptr;
            tail->next = ipCurTime;
            //ipCurTime->prev = tail;
            tail = ipCurTime;
        }

        
    }

    void adjust_time(util_time* ipAdjTime)
    {
        if(!ipAdjTime)
        {
            return ;
        }
        util_time* tmp = head;
        //if(!tmp||ipAdjTime->expire<tmp->expire)
        if(!ipAdjTime->next)
        {
            return;
        }
        if(ipAdjTime==head)
        {
            head = head->next;
            //head->prev = NULL;
            //ipAdjTime->next = NULL;
        }
        //else
        //{
        //    //ipAdjTime->prev->next = ipAdjTime->next;
        //    ipAdjTime->next->prev = ipAdjTime->prev;
        //}
        else
        {
            while(tmp&&tmp->next&&tmp->next!=ipAdjTime)
            {
                tmp=tmp->next;
            }
            if(tmp->next)
            {
                if(tmp->next==tail)
                {
                    tail = tmp;
                }
                tmp->next = ipAdjTime->next;
            }
            else
            {
                return ;
            }
        }

        add_time(ipAdjTime);
        return;
    }

    void del_time(util_time* ipDelTime)
    {
        if(!ipDelTime)
        {
            return;
        }

        if(ipDelTime==head)
        {
            head = ipDelTime->next;
            delete ipDelTime;
            ipDelTime = nullptr;
            return;
        }

        util_time* tmp = head;
        while(tmp&&tmp->next&&tmp->next!=ipDelTime)
        {
            tmp=tmp->next;
        }
        if(tmp->next)
        {
            if(tmp->next==tail)
            {
                tail = tmp;
            }
            tmp->next = ipDelTime->next;
            delete ipDelTime;
            ipDelTime = nullptr;
            
        }
        else
        {
            delete ipDelTime;
            ipDelTime = nullptr;
        }

        return ;
    }

    void tick()
    {
        if(!head)
        {
            return;
        }
        printf("time tick!\n");
        time_t curTime = time(NULL);
        util_time* tmp = head;
        while(tmp&&tmp->expire<curTime)
        {
            tmp->cb_func(tmp->user_data);
            head=tmp->next;
            del_time(tmp);
            tmp = head;
        }
    }
};
#endif