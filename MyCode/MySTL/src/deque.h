#ifndef MYSTL_DEQUE_H
#define MYSTL_DEQUE_H
namespace mystl
{
    #ifndef DEQUE_MAP_INIT_SIZE
    #define DEQUE_MAP_INIT_SIZE 8
    #endif

    template<class T>
    struct deque_buf_size
    {
        static constexpr size_t value =sizeof(T)<256?4096/sizeof(T):16;

    };

    template<class T,class Ref,class Ptr>
    struct deque_iterator
    {
        typedef deque_iterator<T,T&,T*>                  iterator;
        typedef deque_iterator<T,const T&,const T*>      const_iterator;
        typedef deque_iterator                           self;

        typedef T                   value_type;
        typedef Ptr                 pointer;
        typedef Ref                 reference;
        typedef size_t              size_type;
        typedef ptrdiff_t           defference_type;
        typedef T*                  value_pointer;
        typedef T**                 map_pointer;

        static const size_type   buffer_size = deque_buf_size<T>::value;

        //迭代器所含成员数据
        value_pointer   cur;
        value_pointer   first;
        value_pointer   last;//尾部指针指向最后一个元素的下一个元素，因为它不能被使用
        map_pointer     node;

        //构造、拷贝、移动
        deque_iterator() noexcept
        :cur(nullptr)
        ,first(nullptr)
        ,last(nullptr)
        ,node(nulltr)
        {}

        depue_iterator(value_pointer v,map_pointer n)
        :cur(v)
        ,first(*n)
        ,last(*n+buffer_size)
        ,node(n)
        {}

        deque_iterator(const iterator &rhs)
        :cur(rhs.cur)
        ,first(rhs.first)
        ,last(rhs.last)
        ,node(rhs.node)
        {

        }

        self& operator=(const iterator &rhs)
        {
            if (this!=rhs)
            {
                cur = rhs.cur;
                first = rhs.first;
                last = rhs.last;
                node = rhs.node;
            }

            return *this;
            
            
        }


        void set_node(map_pointer new_node)
        {
            node = new_node;
            first = *new_node;
            last = first+buffer_size;
        }


        //重载运算符
        reference operator*(){return *cur}

        pointer operator->(){return cur}


        //递增递减

        //前置递增递减返回引用
        self& operator++()
        {
            ++cur;
            if (cur==last)
            {
                set_node(node+1);
                cur=first;
            }
            return *this;
            
        }  

        self operator++(int)
        {
            self temp = *this;
            ++*this;
            return temp;
        }


        self& operator--()
        {
            if (cur==first)
            {
                set_node(node-1);
                cur =  last;
            }
            --cur;
            return *this;
        }

        self operator--(int)
        {
            self tmp = *this;
            --*this;

            return tmp;
        }


        self operator+=(difference_type n)
        {
            const auto offset = n+cur-first;

            if (offset>=0&&offset<static_cast<difference_type>(buffer_size))
            {
                cur +=n              /* code */
            }
            else
            {
                const auto node_offset = offset>0?offset/static_cast<difference_type>(buffer_size):-static_cast<difference_type>((-offset-1)/buffer_size)-1;
                set_node(node-node_offset);

                cur = first+(offset-node_offset*static_cast<differnece_type>(buffer_size));

            }
            return *this;
        }

        reference operator[](difference_type n)const {return *(*this+n)}


        




    };
























}






#endif