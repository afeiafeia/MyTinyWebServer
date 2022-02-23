#ifndef MY_STL_HEAP_H
#define MY_STL_HEAP_H

#include <vector>
#include <exception>
template<class T>
class mystl_heap
{
private:
    std::vector<T>      m_data;

public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef T&          reference;
    typedef size_t      size_type;


public:
    void push(value_type& value);
    value_type pop();
    void sort();

    template<typename Iterator> void make_heap(Iterator first,Iterator last);

};

template<typename T>
void mystl_heap<T>::push(value_type &value)
{
    size_type oldSize = m_data.size();
    m_data.push_back(value);
    size_type newSize = oldSize+1;

    int lastIndex = oldSize-1;
    int pushIndex = lastIndex+1;
    int fatherIndex = (lastIndex-1)>>1;
    if((lastIndex&1)==0)
    {
        //插入前，最后一个元素在右节点；
        int curIndex = lastIndex;
        int curLevel = 0;
        while(curIndex)
        {
            curIndex = curIndex>>1;
            curLevel++;
        }
        int lastIndexAtCurLevel = (1>>curLevel)-2;
        if(lastIndex<lastIndexAtCurLevel)
        {
            //当前层还有空位置
            fatherIndex;
        }

    }
    while(pushIndex>0&&m_data[pushIndex]<m_data[lastIndex])
    {
        value_type tmp    = m_data[pushIndex];
        m_data[pushIndex] = m_data[lastIndex];
        m_data[lastIndex] = tmp;

        pushIndex = fatherIndex;
        fatherIndex = (pushIndex-1)>>1;
    }

}

template<typename T>
mystl_heap<T>::value_type mystl_heap<T>::pop()
{
    if(m_data.empty())
    {

    }
    size_type oldSize = m_data.size();
    int lastIndex = (int)oldSize-1;
    if(lastIndex==0)
    {
        return m_data[0];
    }

    value_type tmp = m_data[0];
    m_data[0] = m_data[lastIndex];
    m_data[lastIndex] = tmp;
    
    int fatherndex = 0;
    int leftCLIndex = 1;
    int rightCLIndex = 2;
    while(leftCLIndex<lastIndex
    &&(m_data[fatherndex]<m_data[leftCLIndex]||m_data[fatherndex]<m_data[rightCLIndex]))
    {
        if(m_data[leftCLIndex]<m_data[rightCLIndex])
        {
            //交換父节点与左子节点的值
            value_type tmp = m_data[fatherndex];
            m_data[fatherndex] = m_data[leftCLIndex];
            m_data[leftCLIndex] = tmp;

            fatherndex = leftCLIndex;
            leftCLIndex = 2*fatherndex+1;
            rightCLIndex = 2*fatherndex+2;
        }
        else
        {
            //交換父节点与左子节点的值
            value_type tmp = m_data[fatherndex];
            m_data[fatherndex] = m_data[rightCLIndex];
            m_data[rightCLIndex] = tmp;

            fatherndex = rightCLIndex;
            leftCLIndex = 2*fatherndex+1;
            rightCLIndex = 2*fatherndex+2;
        }
    }
    m_data.pop_back();
    return tmp;



}


template<typename T>
template<typename Iterator>
void mystl_heap<T>::make_heap(Iterator first,Iterator last)
{
    //左闭右开
    m_data.assign(first,last);
    size_type size = last-first;
    if(size<1)
    {
        return ;
    }
    int lastIndex = (int)size-1;
    int level = 1;
    int levelLastIndex = 0;
    while(levelLastIndex<lastIndex)
    {
        level++;
        levelLastIndex = (1<<level)-2;
    }
    while(level>1)
    {
        int curLevelStIndex = (1<<(level-1))-1;
        int curLevelEdIndex = (1<<level)-2;

        int fatherIndex = (curLevelEdIndex-1)/2;
        int brotherIndex = curLevelEdIndex-1;

        if(curLevelEdIndex&1
        &&m_data[fatherIndex]<m_data[curLevelEdIndex])
        {
            //curLevelEdIndex是左节点
            value_type tmp = m_data[fatherIndex];
            m_data[fatherIndex] = m_data[curLevelEdIndex];
            m_data[curLevelEdIndex] = tmp;
            curLevelEdIndex--;

        }

        while(curLevelEdIndex>=curLevelStIndex)
        {
            fatherIndex = (curLevelEdIndex-1)/2;
            brotherIndex = curLevelEdIndex-1;
            
            if(m_data[fatherIndex]<m_data[curLevelEdIndex]
            ||m_data[fatherIndex]<m_data[brotherIndex])
            {
                int swapIndex = m_data[curLevelEdIndex]<m_data[brothreIndex]?curLevelEdIndex:brotherIndex;
                value_type tmp = m_data[swapIndex];
                m_data[swapIndex] = m_data[fatherIndex];
                m_data[fatherIndex] = tmp;
            }
            curLevelEdIndex-=2;
        }
        level--;
    }

}

#endif