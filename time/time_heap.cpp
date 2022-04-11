#include "time_heap.h"
#include <unistd.h>
time_heap::time_heap(int capacity)
{
    if(capacity>m_vctTimer.capacity())
    {
        m_vctTimer.reserve(capacity);
    }
}

void time_heap::add_time(util_time* ipAddTime)
{
    if(ipAddTime==nullptr)
    {
        return;
    }

    m_vctTimer.push_back(ipAddTime);

    int curIndex = (int)m_vctTimer.size()-1;//最后一个元素的下标
 
    int fatherIndex = (curIndex-1)/2;//父节点的下标
    util_time* lastNodeFather = nullptr;

    if(curIndex&1==0)
    {
        //curIndex为偶数
        //说明当前完全二叉树最后一个节点是右节点
        //则下一个插入元素的位置，是fatherIndex+1位置节点的左节点
        fatherIndex++;
    }
    //过期时间最小（最近要过期）的节点上浮
    while(curIndex>0&&m_vctTimer[curIndex]->m_expire<m_vctTimer[fatherIndex]->m_expire)
    {
        std::swap(m_vctTimer[curIndex],m_vctTimer[fatherIndex]);
        curIndex =fatherIndex;
        fatherIndex = (curIndex-1)/2;
    }

}

void time_heap::del_time()
{
    if(m_vctTimer.empty())
    {
        return;
    }
    //交换第一个和最后一个元素
    std::swap(m_vctTimer[0],m_vctTimer.back());
    delete m_vctTimer.back();

    //下滤操作
    int lastIndex = m_vctTimer.size()-2;
    int fatherIndex = 0;
    int childIndex = 1;
    while(childIndex<=lastIndex&&m_vctTimer[childIndex]<m_vctTimer[fatherIndex])
    {
        if(childIndex&1==1)
        {
            //为奇数说明为左节点
            if(childIndex<lastIndex)
            {
                //说明有右兄弟
                if(m_vctTimer[childIndex]->m_expire>m_vctTimer[childIndex+1]->m_expire)
                {
                    //右边更小
                    childIndex++;
                }
            }
        }
        std::swap(m_vctTimer[childIndex],m_vctTimer[fatherIndex]);
        fatherIndex = childIndex;
        childIndex = 2*fatherIndex+1;

    }
    //移除最后一个元素
    m_vctTimer.erase(m_vctTimer.end()-1);

}

void time_heap::tick()
{
    time_t cur = time(NULL);
    while(!m_vctTimer.empty())
    {
        util_time* topTime = m_vctTimer[0];
        if(topTime->m_expire>cur)
        {
            //如果最小的过期时间也没有过期，说明没有过期节点，直接退出
            break;
        }
        topTime->cb_func(topTime->m_pUser_data);
        del_time();
    }
}