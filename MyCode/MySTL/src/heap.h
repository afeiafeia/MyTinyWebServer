#ifndef MYSTL_HEAP_H
#define MYSTL_HEAP_H
#include <vector>
namespace mystl
{

    template<typename T>class heap
    {
    public:
        typedef T*       pointer;
        typedef T&       referencr;
        typedef size_t   size_type;
        typedef T        value_type;

        std::vector<T>  vctValue;

        pointer    start; //指向第一个元素
        pointer    end;   //指向最后一个元素
        size_type  size;
        

        void push(value_type &value);

        value_type pop();

        void sort();

        template<typename Iterator>  void make_heap(Iterator first,Iterator last);




    };





    template<typename T>
    void heap<T>::push(value_type &value)
    {
        if(end-start+1==size)//不能再添加元素
        return;
        size_type curIndex = size-1;//最后一个元素的下标
 
        size_type fatherIndex = (curIndex-1)/2;//父节点的下标
        pointer lastNodeFather = nullptr;

        if(curIndex&1==0)
        {
            //curIndex为偶数
            //说明当前完全二叉树最后一个节点是右节点
            //则下一个插入元素的位置，是fatherIndex+1位置节点的左节点
            fatherIndex++;
        }
        lastNodeFather = start+fatherIndex;
        end++;
        size++;
        *end = value;
        while(end!=start&&value>*lastNodeFather)
        {
            //交换子节点与父节点的值
            value_type tmp = *lastNodeFather;
            *lastNodeFather = value;
            *end = tmp;

            fatherIndex = (fatherIndex-1)/2;
            end = lastNodeFather;
            lastNodeFather = start+fatherIndex;

        }

        end = start+size-1;


    }

    template<typename T>
    typename heap<T>::value_type heap<T>::pop()
    {
        //交换首尾的值
        value_type endTmp = start[size-1];
        start[--size] = start[0];//并缩小堆的尺寸
        end--;
        start[0] = endTmp;

        size_type fatherIndex = 0;
        size_type childIndex = fatherIndex*2+1;
        if(childIndex<size-1&&start[childIndex]<start[childIndex+1])
        {
            //交换左节点与父节点的值
            childIndex++;         
        }

        while(childIndex<size&&start[fatherIndex]<start[childIndex])
        {
            value_type tmpChild = start[childIndex];
            start[childIndex] = start[fatherIndex];

            start[fatherIndex] = tmpChild;

            fatherIndex = childIndex;
            childIndex = fatherIndex*2+1;


            if(childIndex<size-1&&start[childIndex]<start[childIndex+1])
            {
                //交换左节点与父节点的值
                childIndex++;
                
            }

        }

        return *end;


    }

    template<typename T>
    template<typename Iterator>
    void heap<T>::make_heap(Iterator first,Iterator last)//左右都是闭区间
    {
        size_type levelCount=1;
        size_type size = last-first;
        if(size<2)
        return;
        size_type curIndex = 2*levelCount;//该层最后一个节点的下标
        while(curIndex-1<size)
        {
            levelCount++;
            curIndex*=2; 
        }
        size_type lastIndex = size--;//最后一个节点的下标
        size_type fatherIndex = (lastIndex-1)/2;

        if(lastIndex&1!=0)
        {
            //奇数为左节点
            //说明最后一个是左节点，没有右子节点，下面的循环针对左右子节点都存在的情况，这里相当于特殊处理
            if(start[lastIndex]>start[fatherIndex])
            {
                value_type tmp = start[lastIndex];
                start[lastIndex]=start[fatherIndex];
                start[fatherIndex] = tmp;
            }
            lastIndex--;
            fatherIndex = (lastIndex-1)/2;

        }

        for(;levelCount>0;levelCount--)
        {
            size_type levelStIndex = 0;
            size_type i = levelCount;
            while(i--)
            {
                levelStIndex=2*levelStIndex+1;//当前层的起始节点的下标
            }
            levelStIndex = (levelStIndex+1)/2-1;
            while(lastIndex>=levelStIndex)
            {
               
                //lastIndex是右节点
                lastIndex = start[lastIndex]<start[lastIndex-1]?lastIndex-1:lastIndex;
                if(start[lastIndex]>start[fatherIndex])
                {
                    value_type tmp = start[lastIndex];
                    start[lastIndex]=start[fatherIndex];
                    start[fatherIndex] = tmp;
                }

                if(lastIndex&1==0)
                {
                    lastIndex-=2;
                }
                else
                {
                    lastIndex--;
                }
                fatherIndex = (lastIndex-1)/2;
           }
           lastIndex = levelStIndex-1;
        }

    }


    template<typename T>
    template<typename Iterator>
    void heap<T>::make_heap(Iterator first,Iterator last)//左右都是闭区间
    {
        start = first;
        end =last+1;
        int size = last-first+1;
        int lastIndex = size-1;
        int fatherIndex = (lastIndex-1)/2;
        for(int i=fatherIndex;i>=0;i--)
        {
            fatherIndex = i;
            int childIndex = 2*fatherIndex+1;

            while(childIndex<size)
            {
                if(childIndex<lastIndex&&start[childIndex]<start[childIndex+1])
                {
                    childIndex++;
                }
                if(start[childIndex]>start[fatherIndex])
                {
                    mystl::swap(start[childIndex],start[fatherIndex]);
                    fatherIndex = childIndex;
                    childIndex = 2*fatherIndex+1;
                }
                else
                {
                    break;
                }
            }


        }



    }

    template<class T> void heap<T>::sort()//不断pop也可实现
    {
        
        //对0到size-1元素重建堆
        for(int i=size-1;i>=1;i--)
        {
            //交换第一个和最后一个元素位置
            mystl::swap(start[0],start[i]);
            make_heap(&start[0],&start[i-1]);
        }
    }



}

#endif