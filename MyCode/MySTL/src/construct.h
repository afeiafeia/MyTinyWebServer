#ifndef MYSTL_CONSTRUCT_H
#define MYSTL_CONSTRUCT_H

#include <type_traits>
#include <bits/move.h>
#include "iterator.h"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)  // unused parameter
#endif // _MSC_VER

namespace mystl
{
    template<class T>
    void construct(T* ptr)
    {
        ::new((void*)ptr)T();

    }
    template<class T1,class T2>
    void construct(T1* ptr,const T2 &reference)
    {
        ::new((void*)ptr)T1(reference);
    }


    template<class T,class... Args>
    void construct(T* ptr,Args&&... args)
    {
        //forward完美转发，如果传给construct的参数args是左值，通过引用折叠，Args是左值引用，这是，如果Ty的参数也是右值引用，则args无法传给它，通过forward，会返回一个左值引用，是的可以传给Ty
        //forward返回Args类型的&&,如果Args是左值引用，通过引用折叠，最终返回的是左值引用

        //如果传给construct的参数是右值，Args就是一个不带引用的类型，args就是一个左值，如果Ty是右值引用，则参数无法传给Ty,这时，forward返回右值引用，可以继续传递Ty

        //实现上，forward与move虽然类似，但还是不同的：
        //（1）forward必须通过显示模板实参来调用，即，使用forward时必须加上见括号<>,forward<T>，而不能直接使用forward(args)；但是move是可以的，move不用显示实例化直接使用move(args)即可
        //（2）move操作对象是一个左值，然后把返回对象赋值给一个右值引用，即一定是这种使用方式：Type(具体类型) && = std::move(一个左值) 

        //显示模板实例化：每次调用是加上尖括号，尖括号中是一个类型（可以是具体类型，也可以是模板类型参数（如果是模板类型参数，该forward一定是在一个模板函数中被调用的情况，如本例））
        ::new ((void*)ptr) T(std::forward<Args>(args)...);
    }


    //析构对象
    template<class T>
    void destroy_one(T* ptr)
    {
        if(ptr!=nullptr)
        {
            ptr->~T();
        }
    }

    template<class T>
    void destroy(T* first,T* last)
    {
        for(;first!=last;first++)
        {
            destroy_one(first);
        }
    }

    template<class ForwardIter>
    void destroy_cat(ForwardIter,ForwardIter,std::true_type)
    {

    }

    template<class ForwardIter>
    void destroy_cat(ForwardIter first,ForwardIter last,std::false_type)
    {
        for(;first!=last;first++)
        {
            destroy(&*first);
        }
    }

    template<class ForwardIter>
    void destroy_cat(ForwardIter first,ForwardIter last)
    {
        destroy_cat(first,last,std::is_trivially_destructible<typename iterator_traits<ForwardIter>::value_type>{});
    }


}

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif