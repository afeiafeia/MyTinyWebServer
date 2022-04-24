#ifndef MY_STL_ALGOBASE_H
#define MY_STL_ALGOBASE_H

#include "iterator.h"

//基本算法
namespace mystl
{
    template<class T>
    const T& max(const T& lhs,const T& rhs)
    {
        return lhs > rhs ? lhs : rhs;
    }

    template<class T>
    const T& min(const T&lhs,const T& rhs)
    {
        return lhs < rhs ? lhs : rhs;
    }

    template<class T,class Comp>
    const T& max(const T& lhs,const T &rhs,Comp compare)
    {
        return compare(lhs, rhs) ? lhs : rhs;
    }

    template<class T,class Comp>
    const T& min(const T &lhs,const T &rhs,Comp compare)
    {
        return compare(lhs, rhs) ? lhs : rhs;
    }


    template<class Ty>
    class less
    {
    public:
        typedef Ty first_type;
        typedef Ty second_type;
        typedef bool result_type;
    public:
        constexpr bool operator()(const Ty& first,const Ty &second)
        {
            return first < second;
        }
    };

    template<class Ty>
    class greater
    {
    public:
        typedef Ty first_type;
        typedef Ty second_type;
        typedef bool result_type;
    public:
        constexpr bool operator()(const Ty &first,const Ty &second)
        {
            return first > second;
        }
    };

    template<class Iterator,class Comp>
    void sort(Iterator first,Iterator last,Comp compare)
    {
        typename iterator_traits<Iterator>::difference_type n = mystl::distance(first,last);
        typename iterator_traits<Iterator>::difference_type m = n;
        for (int i=0;i<n;i++,m--)
        {
            auto cur = first;
            for (int j = 1; j<m; j++)
            {
                auto next = cur;
                next++; 
                if (!compare(*cur, *next))
                {
                    typename iterator_traits<Iterator>::value_type tmp = *cur;
                    *cur = *next;
                    *next = tmp;
                }
                cur = next;
            }
        }
    }

    template<class InputIter,class OutputIter>
    OutputIter
    unchecked_copy_cat(InputIter first,InputIter last,OutputIter result,mystl::input_iterator_tag)
    {
        for(;first!=last;++first,++result)
        {
            mystl::construct(&*result,*first);
        }
        return result;
    }


}


#endif