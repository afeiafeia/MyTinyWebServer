#ifndef MYSTL_ITERATOR_H
#define MYSTL_ITERATOR_H

#include <cstddef>
#include <type_traits>
#include "type_traits.h"
namespace mystl
{

//以下这些tag标识迭代器的类型
struct input_iterator_tag {};//只读迭代器
struct output_iterator_tag{};//只写迭代器
struct forward_iterator_tag : public input_iterator_tag,output_iterator_tag{};//可读可写
struct bidirectional_iterator_tag : public forward_iterator_tag{};//可以双向移动
struct random_access_iterator_tag : public bidirectional_iterator_tag{};

//Category是迭代器类型（上面的tag），T是迭代器所指的对象的类型
template<class Category,class T,class Distance = ptrdiff_t,class Pointer = T*,class Reference = T&>
struct iterator
{
    typedef Category             iterator_category;
    typedef T                    value_type;
    typedef Pointer              pointer;
    typedef Reference            reference;
    typedef Distance             difference_type;
};

//判断迭代器是否有category
template<class T>
struct has_iterator_cat
{
private:
    struct two{char a;char b;};
    template <class U>static two test(...);
    template <class U>static char test(typename U::iterator_category* = 0);
public:
    static const bool value = sizeof(test<T>(0))==sizeof(char);
};

template<class Iterator,bool>
struct iterator_traits_impl{};

template<class Iterator>
struct iterator_traits_impl<Iterator,true>
{
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type        value_type;
    typedef typename Iterator::pointer           pointer;
    typedef typename Iterator::reference         reference;

};

template <class Iterator,bool>
struct iterator_traits_helper{};

//std::is_convertible<class A,class B>
//判断是否可以将类型A转换成类型B
template<class Iterator>
struct iterator_traits_helper<Iterator,true>
    : public iterator_traits_impl<Iterator,
    std::is_convertible<typename Iterator::iterator_category, input_iterator_tag>::value ||
    std::is_convertible<typename Iterator::iterator_category, output_iterator_tag>::value>
{

};
//如果不是原生指针，就会匹配这个iterator_traits,这时，对于传入的类Iterator，会判断它是不是迭代器类型，是迭代器，才有内置类型，
//否则，如果一个class不是迭代器类型，那么获取它的内置类型时，编译时就会出错，便于提前检查出错误。
template<class Iterator>
struct iterator_traits:public iterator_traits_helper<Iterator,has_iterator_cat<Iterator>::value>
{

};

template<class T>
struct iterator_traits<T*>
{
    typedef random_access_iterator_tag      iterator_category;//对于原生指针，它的category类型是一个随机访问迭代器类型：random_access_iterator_tag
    typedef T                               value_type;
    typedef T*                              pointer;
    typedef T&                              reference;
    typedef ptrdiff_t                       difference_type;
};

template<class T>
struct iterator_traits<const T*>
{
    typedef random_access_iterator_tag     iterator_category;
    typedef T                              value_type;
    typedef const T*                       pointer;
    typedef const T&                       reference;
    typedef ptrdiff_t                      difference_type;
};


//萃取迭代器的category
template<class Iterator>
typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&)
{
    typedef typename iterator_traits<Iterator>::iterator_category Category;
    return Category();
}

template<class Iterator>
typename iterator_traits<Iterator>::value_type*
value_type(const Iterator &)
{
    typedef typename iterator_traits<Iterator>::value_type value_type;
    return static_cast<value_type *>(0);//这里为什么返回指针？？？
}

template<class Iterator>
typename iterator_traits<Iterator>::difference_type*
distance_type(const Iterator &)
{
    return static_cast<typename iterator_traits<Iterator>::defference_type *>(0);
}


//计算迭代器之间的距离

//（1）InputIterator类型迭代器的版本:实际上，前四种迭代器都会调用改版本（因为继承关系）
template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance_dispatch(InputIterator first,InputIterator last,input_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for (; first != last;first++)
    {
        n++;
    }
    return n;
}



//(2)RandomIter
template<class RandomIter>
typename iterator_traits<RandomIter>::difference_type
distance_dispatch(RandomIter first,RandomIter last,random_access_iterator_tag)
{
    return last - first;
}


template<class Iter>
typename iterator_traits<Iter>::difference_type
distance(Iter first,Iter last)
{
    return distance_dispatch(first,last,iterator_category(first));
}


template<class T,class U,bool = has_iterator_cat<iterator_traits<T>>::value>
struct has_iterator_cat_of
    :public m_bool_constant<std::is_convertible<typename iterator_traits<T>::iterator_category,U>::value>
{

};
template<class T,class U>
struct has_iterator_cat_of<T,U,false>:public m_false_type{};

template<class Iter>
struct is_input_iterator
    :public has_iterator_cat_of<Iter,input_iterator_tag>{};





}






#endif
