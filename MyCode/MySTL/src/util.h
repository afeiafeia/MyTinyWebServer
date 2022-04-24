#ifndef MY_STL_UTIL_H
#define MY_STL_UTIL_H


//包含一些通用的基本工具：move、forward、swap
#include <cstddef>
#include <type_traits>
namespace mystl
{
    //move
    template<class T>
    typename std::remove_reference<T>::type&& move(T&& arg)
    {
        //当将一个左值传递给函数的右值引用参数时，且此右值引用指向模板类型参数时，编辑器将推断该模板类型参数为实参的左值引用类型
        //当传递右值的时候，模板实参被推断为该右值的实际类型
        return static_cast<typename std::remove_reference<T>::type &&>(arg);
    }

    //forward
    template<class T>
    T&& forward(typename std::remove_reference<T>::type& arg)
    {
        return static_cast<T&&>(arg);
    }

    template<class T>
    T&& forward(typename std::remove_reference<T>::type&& arg)
    {
        return static_cast<T &&>(arg);
    }

    //swap
    template<class Ty>
    void swap(Ty& lhs,Ty& rhs)
    {
        auto tmp(mystl::move(lhs));
        lhs = mystl::move(rhs);
        rhs = mystl::move(tmp);
    }










}



#endif