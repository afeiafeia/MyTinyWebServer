#ifndef MYSTL_ALLCATOR_H
#define MYSTL_ALLCATOR_H

#include "construct.h"
#include "iterator.h"
namespace mystl
{
    template <class T> class allocator
    {
    public:
        typedef T         value_type;
        typedef T*        pointer;
        typedef const T*  const_pointer;
        typedef T&        reference;
        typedef const T&  const_reference;

        typedef size_t    size_type;

        public:
        static T* allocate();
        static T* allocate(size_type n);

        static void deallocator(T* ptr);
        static void deallocator(T* ptr,size_type n);

        static void construct(T* ptr);
        static void construct(T* ptr,const T &value);
        //static void construct(T* ptr,const_reference value);
        static void construct(T* ptr,T&& value);


        template <class... Args> 
        static void construct(T* ptr,Args&& ...args);

        static void destroy(T* ptr);
        static void destroy(T* first,T* last);
    };



    template<class T> T* allocator<T>::allocate()
    {
        //注意区分operator new与new operator；
        //一般在C++中使用的new是指后者，它做两件事情：一是分配足够的内存，二是在这块内存上构造对象
        //其中第一步即是调用前者operator new
        //operator new仅仅是根据输入参数分配内存
        return static_cast<T*>(::operator new(sizeof(T)));
    }
    
    template<class T> T* allocator<T>::allocate(size_type n)
    {
        if(n==0)
        return nullptr;
        return static_cast<T*>(::operator new(n*sizeof(T)));
    }

    template<class T> void allocator<T>::deallocator(T* ptr)
    {
        if(ptr==nullptr)
        return ; 
        ::operator delete(ptr);
    }

    template <class T> void allocator<T>::deallocator(T* ptr,size_type)
    {
        if(ptr==nullptr)
        return ;
        ::operator delete(ptr);
    }
    
    template <class T> void allocator<T>::construct(T* ptr)
    {
        //该函数用来在一块已经存在的内存上构造对象
        mystl::construct(ptr);
        
        //::new ((void*)ptr) T();
    }

    template <class T>void allocator<T>::construct(T* ptr,const T& value)
    {
        mystl::construct(ptr,value);
    }

    template <class T>void allocator<T>::construct(T* ptr,T&& value)
    {
        //虽然value作为形参是一个右值引用，但其一旦得到值，它就是一个左值，因此，进入函数体之后，它就成了一个左值
        //std::move()表示，value这个左值要传给一个右值引用（形参），而右值引用不能直接绑定到左值，使用move后，就可以将引用绑定到该左值
        mystl::construct(ptr,std::move(value));
    }

    template<class T>
    template<class ...Args>
    void allocator<T>::construct(T* ptr,Args&& ...args)
    {
        mystl::construct(ptr,std::forward<Args>(args)...);
    }

    template<class T>void allocator<T>::destroy(T* ptr)
    {
        mystl::destroy(ptr);
    }

    template<class T>void allocator<T>::destroy(T* first,T* last)
    {
        mystl::destroy(first,last);
    }

}  //namespace mystl

#endif//!MYSTL_ALLOCATOR_H