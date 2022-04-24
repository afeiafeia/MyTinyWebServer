#ifndef MYSTL_LIST_H
#define MYSTL_LIST_H

#include "allocator.h"
namespace mystl
{
    template <class T> struct list_node_base;
template <class T> struct list_node;

template <class T>
struct node_traits
{
  typedef list_node_base<T>* base_ptr;
  typedef list_node<T>*      node_ptr;
};

// list 的节点结构

template <class T>
struct list_node_base
{
  typedef typename node_traits<T>::base_ptr base_ptr;
  typedef typename node_traits<T>::node_ptr node_ptr;

  base_ptr prev;  // 前一节点
  base_ptr next;  // 下一节点

  list_node_base() = default;

  node_ptr as_node()
  {
    return static_cast<node_ptr>(self());
  }

  void unlink()
  {
    prev = next = self();
  }

  base_ptr self()
  {
    return static_cast<base_ptr>(&*this);
  }
};

template <class T>
struct list_node : public list_node_base<T>
{
  typedef typename node_traits<T>::base_ptr base_ptr;
  typedef typename node_traits<T>::node_ptr node_ptr;

  T value;  // 数据域

  list_node() = default;
  list_node(const T& v)
    :value(v)
  {
  }
  list_node(T&& v)
    :value(mystl::move(v))
  {
  }

  base_ptr as_base()
  {
    return static_cast<base_ptr>(&*this);
  }
  node_ptr self()
  {
    return static_cast<node_ptr>(&*this);
  }
};

template <class T>
struct list_iterator
{
  typedef T                                 value_type;
  typedef T*                                pointer;
  typedef T&                                reference;
  typedef typename node_traits<T>::base_ptr base_ptr;
  typedef typename node_traits<T>::node_ptr node_ptr;
  typedef list_iterator<T>                  self;

  base_ptr node_;  // 指向当前节点

  // 构造函数
  list_iterator() = default;
  list_iterator(base_ptr x)
    :node_(x) {}
  list_iterator(node_ptr x)
    :node_(x->as_base()) {}
  list_iterator(const list_iterator& rhs)
    :node_(rhs.node_) {}

  // 重载操作符
  reference operator*()  const { return node_->as_node()->value; }
  pointer   operator->() const { return &(operator*()); }

  self& operator++()
  {
    MYSTL_DEBUG(node_ != nullptr);
    node_ = node_->next;
    return *this;
  }
  self operator++(int)
  {
    self tmp = *this;
    ++*this;
    return tmp;
  }
  self& operator--()
  {
    MYSTL_DEBUG(node_ != nullptr);
    node_ = node_->prev;
    return *this;
  }
  self operator--(int)
  {
    self tmp = *this;
    --*this;
    return tmp;
  }

  // 重载比较操作符
  bool operator==(const self& rhs) const { return node_ == rhs.node_; }
  bool operator!=(const self& rhs) const { return node_ != rhs.node_; }
};

template <class T>
class list
{
public:
    typedef mystl::allocator<T>        allocator_type;
    typedef mystl::allocator<T>        data_allocator;

    typedef mystl::allocator<list_node_base<T>> base_allocator;
    typedef mystl::allocator<list_node<T>>      node_allocator;

    typedef typename allocator_type::value_type      value_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef list_iterator<T>                         iterator;
    //typedef list_const_iterator<T>                   const_iterator;
    typedef mystl::reverse_iterator<iterator>        reverse_iterator;
    //typedef mystl::reverse_iterator<const_iterator>  const_reverse_iterator;

    typedef typename node_traits<T>::base_ptr        base_ptr;
    typedef typename node_traits<T>::node_ptr        node_ptr;

private:
    base_ptr node_;
    size_type size_;

public:
    list()
    {
        fill_init(0,value_type());
    }

    explicit list(size_type n)
    {
        fill_init(n,value_type());
    }

    list(size_type n,const T& value)
    {
        fill_init(n,value);
    }


    template<class Iter>
    list(Iter first,Iter last)
    {
        copy_init(first,last);
    }

    void fill_init(size_type n,const value_type &value);
    template<class ...Args>
    node_ptr create_node(Args&& ...args);

    void list_nodes_at_back(base_ptr first,base_ptr last);
    void list_nodes_at_front(base_ptr first,base_ptr last);

    template<class Iter>
    void copy_init(Iter first,Iter last);

    void clear();

    void destroy_node(node_ptr p);

    list& operator=(const list &rhs)
    {
        if (this!=&rhs)
        {
            assign(rhs.begin(),rhs.end());
        }
        return *this;
        
    }


    //迭代器操作
    iterator begin() noexcept
    {
        return node_->next;
    }


    iterator end() noexcept
    {
        return node_;
    }

    void assign(size_type n,const value_type &value)
    {fill_assign(n,value);}

    template<class Iter>
    void assign(Iter first,Iter last)
    {
        fill_assign(first,last);
    }

    void fill_assign(size_type n,const value_type &value);


    //插入元素操作
    iterator insert(const iterator pos,const value_type &value);

    iterator insert(const iterator pos,sise_type n,const value_type &value);
    iterator fill_insert(const iterator pos,sise_type n,const value_type &value);

    template<class Iter>
    iterator insert(const iterator pos,Iter first,Iter last);

    
    iterator link_iter_node(iterator pos,base_ptr link_node);

    void link_nodes(base_ptr pos,base_ptr first,base_ptr last);



    //容量操作
    public:
    bool       empty() const noexcept
    {
        return node_->next==node_;
    }

    size_type size()const noexcept
    {
        return size_;
    }

    //访问元素相关操作
    public:
    reference front()
    {
        MYSTL_DEBUG(!empty());
        return *begin();
    }

    reference back()
    {
        MYSTL_DEBUG(!empty());
        return *end();
    }


    //push操作
    void push_front(const value_type& value)
    {
        auto link_node = create_node(value);
        list_node_at_front(link_node->as_base(),link_node->as_base());
    }

    void push_back(const value_type& value)
    {
        auto link_node = create_node(value);
        list_nodes_at_back(link_node->as_base(),link_node->as_base());
    }


    //pop操作
    void pop_front()
    {
        MYSTL_DEBUG(!empty());
        auto front_node = node_->next;
        node_->next = front_node->next;
        front_node->pre = nullptr;
        destroy_node(front_node->as_node());
        size_--;
    }

    void pop_back()
    {
        MYSTL_DEBUG(!empty());
        auto back_node = node_->pre;
        back_node->pre->next = node_;
        node_->pre = back_node->pre;
        destroy_node(back_node->as_node());
        size_--;
    }

    //emplace操作
    template<class ...Args>
    void emplace_back(Args&& ...args);


    template<class ...Args>
    void emplace_front(Ars&& ...args);

    template<class ...Args>
    void emplace(iterator pos,Args&& ...args);










};
template<class T>
void list<T>::fill_init(size_type n,const value_type &value)
{
    //一个list_node_base类型对象大小的内存
    node_ = base_allocator::allocate(1);
    //节点的前一节点和后一节点都指向自身
    node_->unlink();

    size_ =n;

    try
    {
        for(;n>0;n--)
        {
            auto node = create_node(value);
            //节点放入链表尾部
            link_nodes_at_back(node->as_base(),node->as_base());
        }
    }
    catch(const std::exception& ex)
    {
        clear();
        base_allocator::allocate(node_);
        node_ = nullptr;
        std::cerr << ex.what() << '\n';
        throw;
    }
    
}

template<class T>
template<class ...Args>
typename list<T>::node_ptr
list<T>::create_node(Args&& ...args)
{
    node_ptr p =node_allocator::allocate(1);

    try
    {
        data_allocator::construct(&(p->value),std::forward<Args>(args)...);
        p->prev = nullptr;
        p->next=nullptr;

    }
    catch(const std::exception& e)
    {
        node_allocator::deallocate(p);

        std::cerr << e.what() << '\n';
        throw;
    }
    return p;
}

template<class T>
void list<T>::list_nodes_at_back(base_ptr first,base_ptr last)
{
    last->next = node_;
    first->prev = node_->prev;
    first->prev->next=first;
    node_->prev = last;
}

template<class T>
void list<T>::list_nodes_at_front(base_ptr first,base_ptr last)
{
    last->next = node_->next;
    last->next->pre = last;
    node_->next = first;

}
template<class T>
template<class Iter>
void list<T>::copy_init(Iter first,Iter last)
{
    node_ = base_allocator::allocate(1);
    node_->unlink();

    size_type n=last-first;
    size_ = n;
    try
    {
        for(;n>0;n--,first++)
        {
            auto node = create_node(*first);
            list_nodes_at_back(node->as_base(),node->as_base());
        }
    }
    catch(const std::exception& e)
    {
        clear();
        base_allocator::allocate(node_);
        node_=nullptr;
        std::cerr << e.what() << '\n';
        throw;
    }

}

template <class T>
void list<T>::clear()
{
    //此处的clear并没有释放尾部节点所指的内存，也就是说，node_仍存在
    //它只会在list析构的时候释放
    if(size_!=0)
    {
        auto cur = node_->next;
        for (base_ptr next=cur->next;cur!=node_;cur=next,next=cur->next)
        {
            destroy_node(cur->as_node());
        }
        node_->unlink();
        size_=0;
    }

}


template<class T>
void list<T>::destroy_node(node_ptr)
{
    //destroy是执行T类型对象的析构函数
    data_allocator::destroy(&(p->value));
    //deallocate是释放内存
    node_allocator::deallocate(p);

    //注意不能直接释放内存，因为T类型对象里面可能有指针，直接释放内存，T类型对象指向的动态内存没有释放，
    //直接释放只是释放当前指针p所指的内存，而这块内存中可能有指针又指向其他内存1，这时这块其他内存是没有释放的
}

template<class T>
void list<T>::fill_assign(size_type n,const value_type &value)
{
    auto i=begin();
    auto e = end();

    for(;n>0&&i!=e;n--,i++)
    {
        *i = value;
    }
    if (n>0)
    {
        insert(e,n,value);
    }
    else
    {
        erase(i,e);
    }
    
}



template<class T> typename list<T>::iterator list<T>::insert(const iterator pos,size_type n,value_type &value)
{
    return fill_insert(pos,n,value);
}

template<class T> typename list<T>::iterator list<T>::insert(const iterator pos,const value_type& value)
{
    auto link_node = create_node(value);
    ++size_;
    return link_iter_node(pos,link_node->as_base());
}

template<class T>
typename list<T>::iterator 
list<T>::link_iter_node(iterator pos,base_ptr link_node)
{
    if (pos==node_->node_next)
    {
        link_nodes_at_front(link_node,link_node);
    }
    else if(pos==node_)
    {
        link_nodes_at_back(link_node,link_node);

    }
    else
    {
        link_nodes(pos,node_,link_node,link_node);
    }
    return iterator(link_node);
}


template<class T>
void list<T>::link_nodes(base_ptr pos,base_ptr first,base_ptr last)
{
    first->prev = pos->prev;
    pos->prev->next = first;
    pos->prev = last;
    
    last->next = pos;
}
template<class T>
typename list<T>::iterator 
list<T>::fill_insert(const iterator pos,size_type n,const value_type &value)
{
    iterator(pos.node_);
    if (n!=0)
    {
        const auto add_size = n;
        auto stNode = create_node(value);
        stNode->prev = nullptr;
        iterator end = r;
        try
        {
            for(--n;n>0;--n,++end)
            {
                auto node = create_node(value);
                end.node_->next = node->as_base();
                node->prev = end.node_;
            }
        }
        catch(const std::exception& e)
        {
            auto enode = end.node_;
            while (true)
            {

                auto prev = enode->prev;
                destroy_node(enode->as_node());
                if (prev==nullptr)
                {
                    break;
                    /* code */
                }
                enode = prev;
                
                /* code */
            }
            throw;
            std::cerr << e.what() << '\n';
        }
         
    }
    
}

template<class T>
template<class ...Args>
void list<T>::emplace_back(Args&& ...args)
{
    auto link_node = create_node(std::forward<Args>(args)...);
    list_nodes_at_back(link_node->as_base(),link_node->as_base());
    size_++;

}

template<class T>
template<class ...Args>
void list<T>::emplace_front(Args&& ...args)
{
    auto link_node = create_node(std::forward<Args>(args)...);
    list_nodes_at_front(link_node->as_base(),link_node->as_base());
    size_++;

}

template<class T>
template<class ...Args>
void list<T>::emplace(iterator pos,Args&& ...args)
{
    auto link_node = create_node(std::forward<Args>(args)...);
    link_nodes(pos,link_node->as_base(),link_node->as_base());
    size_++;
    return iterator(link_node);
}




}//namespace mystl

#endif