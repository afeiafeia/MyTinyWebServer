#include "time_wheel.h"
#include <time.h>
time_wheel::time_wheel()
:m_cur_slot(0)
{
    for(int i=0;i<N;i++)
    {
        slots[i]=nullptr;
    }
}

time_wheel::~time_wheel()
{
    for(int i=0;i<N;i++)
    {
        while(slots[i])
        {
            util_time* nextTimer = slots[i]->next;
            delete slots[i];
            slots[i] = nextTimer;
        }
    }
}

util_time* time_wheel::add_time(util_time* ipAdd_Timer)
{
    time_t curTime = time(NULL);
    int timeout = ipAdd_Timer->expire-curTime;
    if(timeout<0)
    {
        return nullptr;
    }
    util_time* curTimer = ipAdd_Timer;
    if(timeout<SI)
    {
        if(slots[0])
        {
            curTimer->next = slots[0];
            slots[0]->prev = curTimer;
            slots[0] = curTimer;
        }
        else
        {
            slots[0] = curTimer;
        }
    }  
    else
    {
        int slotNum  = timeout/SI;
        int rotation = slotNum/N;
        int slotLoc  = ((slotNum%N)+m_cur_slot)%N;

        ipAdd_Timer->m_rotation = rotation;
        ipAdd_Timer->m_time_slot = slotLoc;


        curTimer = ipAdd_Timer;
        if(slots[slotLoc])
        {
            curTimer->next = slots[slotLoc];
            slots[slotLoc]->prev = curTimer;
            slots[slotLoc] = curTimer;
        }
        else
        {
            curTimer->next=nullptr;
            curTimer->prev=nullptr;
            slots[slotLoc] = curTimer;
        }

    }
    return curTimer;
    
}
void time_wheel::del_time(util_time* ipDel_Timer)
{
    if(!ipDel_Timer)
    {
        return;
    }
    util_time* nextTimer = ipDel_Timer->next;
    int slotLoc = ipDel_Timer->m_time_slot;
    if(ipDel_Timer==slots[slotLoc])
    {
        slots[slotLoc] = nextTimer;
        if(nextTimer)
        {
            nextTimer->prev = nullptr;
        }
        delete ipDel_Timer;
        ipDel_Timer = nullptr;
    }
    else
    {
        ipDel_Timer->prev->next = ipDel_Timer->next;
        if(ipDel_Timer->next)
        {
            ipDel_Timer->next->prev = ipDel_Timer->prev;
        }
        delete ipDel_Timer;
        ipDel_Timer = nullptr;
    }

}

void time_wheel::tick()
{
    util_time* curTimer = slots[m_cur_slot];
    while(curTimer)
    {
        //定时器到期，
        if(curTimer->m_rotation==0)
        {
            curTimer->cb_func(curTimer->user_data);
            if(curTimer==slots[m_cur_slot])
            {
                slots[m_cur_slot] = curTimer->next;
                delete curTimer;
                if(slots[m_cur_slot])
                {
                    slots[m_cur_slot]->prev==nullptr;
                }
                curTimer = slots[m_cur_slot];
            }
            else
            {
                curTimer->prev->next = curTimer->next;
                if(curTimer->next)
                {
                    curTimer->next->prev = curTimer->prev;
                }
                util_time* tmpCur = curTimer->next;
                delete curTimer;
                curTimer = tmpCur;
            }
        }
        else
        {
            curTimer->m_rotation--;
            curTimer = curTimer->next;
        }
    }

    m_cur_slot = (++m_cur_slot)%N;
}

void time_wheel::adjust_time(util_time* ipAdj_Timer)
{
    int curSlot = ipAdj_Timer->m_time_slot;
    util_time* head = slots[curSlot];
    if(head==nullptr)
    {
        return;
    }
    if(head!=ipAdj_Timer)
    {
        while(head&&head->next!=ipAdj_Timer)
        {
            head = head->next;
        }
        if(head==nullptr)
        {
            return ;
        }
        head->next = ipAdj_Timer->next;
        if(ipAdj_Timer->next)
        {
            ipAdj_Timer->next->prev = head;
        }

    }
    else
    {
        slots[curSlot] = ipAdj_Timer->next;
        if(ipAdj_Timer->next)
        {
            ipAdj_Timer->next->prev = slots[curSlot];
        }

    }
    add_time(ipAdj_Timer);

}
