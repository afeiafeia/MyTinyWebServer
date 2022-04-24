#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include "allocator.h"
#include "exceptdef.h"
#include <bits/move.h>
#include "util.h"
namespace mystl
{
    template<class T> class vector
    {
    public:

        typedef mystl::allocator<T>   data_allocator;   
        typedef mystl::allocator<T>   allocator_type; 



        typedef T                     value_type;
        typedef value_type*           iterator;
        typedef T&                    reference;
        typedef const T&              const_reference;

        typedef const value_type*     const_iterator;

        //该语句中由于有域解析符::，所有编译器不知道allocator_type::size_type是什么，静态成员变量？静态成员函数？类型？
        //加上了typename就是告诉编译器它是一个类型，如果不加，编译器就不知道它是什么，编译就会出错
        typedef typename allocator_type::size_type       size_type;
    private:
        iterator  m_begin;
        iterator  m_end;
        iterator  m_cap;
        size_type m_size;

    public:
        vector() noexcept
        {
            try
            {
                m_begin = data_allocator::allocate(16);
                m_end = m_begin;
                m_cap = m_begin+16;
            }
            catch(...)
            {
                //设置了noexcept，如果分配失败，不抛出异常
                m_begin = nullptr;
                m_end = nullptr;
                m_capacity = nullptr;
            }
        }
        
        //explicit的作用：如果将一个构造函数声明成explicit，则其他类型就不能隐式转成成这个类型，但是可以显式转换
        explicit vector(size_type n)
        {
            fill_init(n,value_type());
        }
        vector(size_type n,const value_type &value)
        {
            fill_init(n,value);
        }


        //注意左值引用与右值引用的区别：右值引用没有拷贝的过程，直接继承了原参数的空间
        vector(const vector &rhs)
        {
            const size_type rhs_size = static_cast<size_type>(rhs.m_end-rhs.m_begin);
            const size_type init_size = rhs_size>16?rhs_size:16;
            m_begin = data_allocator::allocate(init_size);
            m_end = m_begin+rhs_size;
            m_cap = m_begin+init_size;

            iterator it  = m_begin;
            iterator rhsSt = rhs.m_begin;
            for(;it<m_end;it++,rhsSt++)
            {
                mystl::construct(it,*rhsSt);
            }


        }

        vector(vector &&rhs)
        :m_begin(rhs.m_begin),
        m_end(rhs.m_end),
        m_cap(rhs.m_cap)
        {
            rhs.m_begin = nullptr;
            rhs.m_end = nullptr;
            rhs.m_cap = nullptr;

        }


        template<class Iter>
        vector(Iter first,Iter last)
        {
            range_init(first,last);
        }

        vector& operator=(const vector &rhs);
        vector& operator=(vector &&rhs);

        ~vector()
        {
            //
            data_allocator::destroy(m_begin,m_end);
            data_allocator::deallocator(m_begin,m_cap-m_begin);
            m_begin = nullptr;
            m_end = nullptr;
            m_cap = nullptr;
        }

    public:
        //迭代器相关操作
        iterator begin() const
        { return m_begin;}

        iterator end() const
        {return m_end;}

        const_iterator cbegin() const
        {return m_begin;}

        const_iterator cend() const
        {return m_end;}



        public:
        //容量相关操作
        bool empty() const
        {return m_begin==m_end;}

        size_type size() const
        {return m_end-m_begin;}

        size_type capacity()
        {return m_cap-m_begin;}

        void reserve(size_type n);

        public:
        //访问元素相关操作
        reference operator[](size_type n)
        {
            MYSTL_DEBUG(n<size());
            return *(m_begin+n);

        }

        const_reference operator[](size_type n) const
        {
            MYSTL_DEBUG(n<size());
            return *(m_begin+n);
        }

        reference front()
        {
            MYSTL_DEBUG(!empty());
            return *m_begin;
        }

        const_reference front() const
        {
            MYSTL_DEBUG(!empty());
            return *m_begin;
        }
        reference back()
        {
            MYSTL_DEBUG(!empty());
            return *(m_end-1);
        }
        const_reference back() const
        {
            MYSTL_DEBUG(!empty());
            return *(m_end-1);
        }

        //修改容器相关操作
        void assign(size_type n,const value_type &value)
        {

            fill_init(n,value);
        }

        void assign(iterator first,iterator last)
        {
            MYSTL_DEBUG(last<first);
            copy_assign(first,last);
        }

        //增删查改元素

        void push_back(const value_type &value);
        void push_back(value_type &&value);

        template<class... Args>
        iterator emplace(const_iterator pos,Args&& ...args);

        template <class... Args>
        iterator emplace_back(Args&& ...args);

        iterator erase(const_iterator first,const_iterator last);
        void fill_init(size_type n,const value_type &value);

        void init_space(size_type n,size_type init_size);

        iterator copy_assign(iterator first,iterator last);

        //析构相关操作
        void destroy_and_recover(iterator first,iterator last,size_type n);

        iterator insert(const_iterator pos,const value_type& value);
        iterator insert(const_iterator pos,value_type&& value)
        {
            return emplace(pos,std::move(value));
        }

    private:
        void reallocator_insert(iterator pos,const value_type &value);

        template<class Iter>
        void range_init(Iter first,Iter last);
    };

    template<class T> void vector<T>::fill_init(size_type n,const value_type &value)
    {
        const size_type init_size = n>16?n:16;
        init_space(n,init_size);

        iterator it = m_begin;
        for(;it<m_end;m_begin++)
        {
            mystl::construct(m_begin,value);
        }
    }
    
    template<class T> void vector<T>::init_space(size_type n,size_type init_size)
    {
        m_begin = data_allocator::allocate(n);
        m_end = m_begin+n;
        m_cap = m_begin+init_size;

    }

    template <class T> void vector<T>::reserve(size_type n)
    {
        if(capacity()<n)
        {
            const auto old_size = size();
            iterator new_begin = data_allocator::allocate(n);

            iterator it = m_begin;
            for(;it<m_end;it++)
            {
                data_allocator::construct(new_begin,*it);
            }


        }
    }

    template<class T>
    template<class Iter>
    void vector<T>::range_init(Iter first,Iter last)
    {
        int dis = mystl::distance(first, last);
        int cap = mystl::max(dis,16);

        m_begin = data_allocator::allocate(cap);
        for (int i = 0; i < cap;i++)
        {
            data_allocator::construct(cap);
        }
        m_end = m_begin + cap;
        m_cap = m_begin + cap;
    }

    template <class T> typename vector<T>::iterator vector<T>::copy_assign(iterator first,iterator last)
    {
        auto cur = m_begin;
        for(;first!=last&&cur!=m_end;first++,cur++)
        {
            *cur = *first;
        }
        if(first==last)
        {
            erase(cur,m_end);
        }
        else
        {
            insert(m_end,first,last);
        }
    }

    template<class T> typename vector<T>::iterator vector<T>::erase(const_iterator first,const_iterator last)
    {
        MYSTL_DEBUG(first>=m_begin&&last<=m_end);
        MYSTL_DEBUG(first<=last);
        iterator r = m_begin+(first-m_begin);

        auto cur = first;
        auto next = last;
        for(;next!=m_end;cur++,next++)
        {
            *cur=*next;
        }

       
        data_allocator::destroy(cur,m_end);
        
        m_end = m_end-(last-first);
        return r;


    }

    template<class T> void vector<T>::destroy_and_recover(iterator first,iterator last,size_type n)
    {
        data_allocator::destroy(first,last);
        data_allocator::deallocator(first,n);
    }

    template<class T> void vector<T>::push_back(const value_type &value)
    {
        if(m_end!=m_cap)
        {
            data_allocator::construct(&*m_end,value);
            ++m_end;
        }
        else
        {
            realocate_insert(m_end,value);
        }

    }

    template<class T> void vector<T>::push_back(value_type &&value)
    {
        emplace_back(std::move(value));
    }

    template<class T> void vector<T>::reallocator_insert(iterator pos,const value_type &value)
    {
        const auto new_size = (m_cap-m_begin)<<1;
        auto new_begin = data_allocator::allocate(new_size);
        auto new_end=new_begin;
        const value_type &value_copy=value;

        try
        {
            //new_end = std::uninitialized_move(begin,pos,new_begin);
            data_allocator::construct(&*new_end,value);
            new_end++;
            //new_end = std::uninitialized_move(pos,end,new_end);
        }
        catch(...)
        {
            data_allocator::deallocator(new_begin,new_size);
            throw;
        }
        destroy_and_recover(m_begin,m_end,m_cap-m_begin);
        m_begin = new_begin;
        m_end = new_end;
        m_cap = new_begin+new_size;
    }

    template<class T>
    template<class ...Args>
    typename vector<T>::iterator 
    vector<T>::emplace(const_iterator pos,Args&& ...args)
    {
        //emplace实现在指定位置插入元素，但与inert不同的是，emplace使用可变参数模板，可以直接在pos位置构造对象。只有一次构造
        //insert传入的是一个具体对象，因此，如果需要利用一些参数来在指定位置构造对象，则insert需要先利用这些对象构造一个临时对象传入函数，然后在底层再去调用拷贝构造，两次构造
        //例如利用1.0,2.0,2.5三个double参数构造一个点Point插入到一个vector<Point> vctPnt的某个位置pos
        //如果使用emplace,则直接传入vctPnt.(pos,1.0,2.0,2.5）；
        //如果使用insert，则需要vctPnt.insert(pos,Point(1.0,2.0,2.5))，需要构造一个临时对象，相比emplace，时间、效率都低了。虽然插入一两个元素这个效果不明显，但当数据量很大时就明显了

        MYSTL_DEBUG(pos>=m_begin&&pos<=m_end);
        iterator xpos = const_cast<iterator>(pos);
        const size_type n=xpos-m_begin;
        if(m_end!=m_cap&&xpos==m_end)
        {
            data_allocator::construct(&*m_end,std::forward<Args>(args)...);
            ++m_end;
        }
        else if(m_end!=m_cap)
        {
            auto new_end = m_end;
            data_allocator::construct(&*m_end,*(m_end-1));
            ++new_end;
            //*xpos = value_type(std::forward<Args>(args)...);或者使用下面的方式
            data_allocator::construct(xpos,std::forward<Args>(args)...);
            

        }
        else
        {
            //reallocate_emplace(xpos,std::forward<Args>(args)...);

        }
        return m_begin+n;
    }

    template<class T>
    template<class...Args>
    typename vector<T>::iterator
    vector<T>::emplace_back(Args&& ...args)
    {
        return emplace(m_end-1,mystl::forward<Args>(args)...);
    }



    template<class T>
    vector<T>& vector<T>::operator=(const vector& rhs)
    {
        if(m_size<rhs.size())
        {
            m_begin = data_allocator::allocate(rhs.size());
            m_end = m_begin+rhs.size();
        }
        copy_assign(rhs.begin(),rhs.end());
        return *this;
    }

    template<class T>
    vector<T>& vector<T>::operator=(vector&& rhs)
    {
        destroy_and_recover(m_begin,m_end);

        m_begin = rhs.m_begin;
        m_end   = rhs.m_end;
        m_cap   = rhs.m_cap;

        rhs.m_begin = nullptr;
        rhs.m_end   = nullptr;
        rhs.m_cap   = nullptr;
        return *this;
    }
}


#endif