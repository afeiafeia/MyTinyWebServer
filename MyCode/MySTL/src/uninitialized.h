#ifndef MY_STL_UNINITIALIZED_H
#define MY_STL_UNINITIALIZED_H

#include "iterator.h"
#include "type_traits.h"
#include "construct.h"
namespace mystl
{
    

    template<class InputIter,class ForwardIter>
    ForwardIter
    unchecked_uninit_copy(InputIter first,InputIter last,ForwardIter result,std::true_type)
    {
        ;
    }

    template<class InputIter,class ForwardIter>
    ForwardIter
    unchecked_uninit_copy(InputIter first,InputIter last,ForwardIter result,std::false_type)
    {
        auto cur = result;
        try
        {
            for(;first!=last;++first,++cur)
            {
                //不使用等于号
                mystl::construct(&*cur,*first);
            }
        }
        catch(...)
        {
            //不使用递减运算，因为迭代器不一定有递减运算符，但一定有递增
            for(;result!=cur;++result)
            {
                mystl::destroy(&*result);
            }
        }
        return cur;
    }

    template<class InputIter,class ForwardIter>
    ForwardIter uninitialized_copy(InputIter first,InputIter last,ForwardIter result)
    {
        return unchecked_uninit_copy(first,last,result,ture_type);
    }


    template<class InputIer,class Size,class ForwardIter>
    ForwardIter unchecked_uninit_copy_n(InputIter first,Size n,InputIter last,ForwardIter result,std::true_type)
    {
        ;
    }


    template<class InputIer,class Size,class ForwardIter>
    ForwardIter unchecked_uninit_copy_n(InputIter first,Size n,InputIter last,ForwardIter result,std::false_type)
    {
        auto cur = result;
        try
        {
            for(int i=0;i<n;++i,++first,++cur)
            {
                //不使用等于号
                mystl::construct(&*cur,*first);
            }
        }
        catch(...)
        {
            //不使用递减运算，因为迭代器不一定有递减运算符，但一定有递增
            for(;result!=cur;++result)
            {
                mystl::destroy(&*result);
            }
        }
        return cur;
    }


















}




#endif