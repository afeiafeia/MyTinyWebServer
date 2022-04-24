#ifndef MY_STL_HASH_TABLE_H
#define MY_STL_HASH_TABLE_H

#include "util.h"
#include "type_traits.h"
#include "iterator.h"
#include "vector.h"
namespace mystl
{
//节点定义


template<class T>
struct hashtable_node
{
    hashtable_node* next;//指向下一个元素的指针//链地址法，哈希值相同的元素用链表串接起来
    T               value;//当前节点的元素(是一个键值对（unordered_map）或者单独一个键也是值(unordered_set))



    hashtable_node()=default;//使用=default表示告知编译器合成默认构造函数，可以不用写定义，当然也可以写
    hashtable_node(const T& n)
    :next(nullptr)
    ,value(n)
    {

    }
    hashtable_node(const hashtable &rhs)
    :next(rhs.next)
    ,value(rhs.value){}

    hashtable_node(hashtable &&rhs)
    :next(rhs.next)
    ,value(mystl::move(rhs.value))
    {
        rhs.next = nullptr;
    }
};

template<class T,bool>
struct ht_value_traits_imp
{
    typedef T key_type;    //键
    typedef T mapped_type; //值
    typedef T value_type;  //节点

    template<class Ty>
    static const key_type& get_key(const Ty& value)
    {
        return value;
    }

    template<class Ty>
    static const value_type& get_value(const Ty& value)
    {
        return value;
    }
};

//注意特例化的方式（最全的模板参数列表写在没进行特例化的模板中）
template<class T>
struct ht_value_traits_imp<T,true>
{
    //remove_cv:移除const、vocatile限定词
    typedef typename std::remove_cv<typename T::first_type>::type key_type;    //键
    typedef typename T::second_type                               mapped_type; //值
    typedef T                                                     value_type;  //节点

    template<class Ty>
    static const key_type& get_key(const Ty& value)
    {
        return value.first;
    }

    template<class Ty>
    static const value_type& get_value(const Ty& value)
    {
        return value;
    }
};

//统一上面两种模板
template<class T>
struct ht_value_traits
{
    static constexpr bool is_map = mystl::is_pair<T>::value;

    typedef ht_value_traits_imp<T,is_map>  value_traits_type;
    typedef typename value_traits_type::key_type       key_type;
    typedef typename value_traits_type::mapped_type    mapped_type;
    typedef typename value_traits_type::value_type     value_type;

    template<class Ty>
    static const key_type& get_key(const Ty& value)
    {
        return value_type::get_key(value);
    }

    template<class Ty>
    static const value_type& get_value(const Ty& value)
    {
        return value_traits_type::get_value(value);
    }
};

//前置声明
template<class T,class HashFun,class KeyEqual>
class hashtable;

template<class T,class HashFun,class KeyEqual>
class ht_iterator;

template<class T,class HashFun,class KeyEqual>
class ht_const_iterator;

template<class T>
struct ht_local_iterator;

template<class T>
struct ht_const_local_iterator;

//迭代器:迭代器里面存放指针：指向元素，迭代器不存放元素（即节点node）
template<class T,class Hash,class KeyEqual>
struct ht_iterator_base:public mystl::iterator<mystl::forward_iterator_tag,T>
{
    typedef mystl::hashtable<T,Hash,KeyEqual>       hashtable;
    typedef ht_iterator_base<T,Hash,KeyEqual>       base;   //定义了一个自身的别名，用于下面的函数中，不然名称太长，麻烦
    
    
    typedef hashtable_node<T>*                      node_ptr;
    typedef hashtable*                              contain_ptr;
    typedef const node_ptr                          const_node_ptr;


    typedef size_t                                  size_type;
    typedef ptrdiff_t                               difference_type;

    node_ptr           node;//指向节点的指针
    contain_ptr        ht;//记录所属的hash表是因为：当++或者--时，可能会进行下一个桶单元，仅依靠node_ptr只能在一条链表上走


    ht_iterator_base()=default;

    bool operator==(const base& rhs){return node==rhs.node;}
    bool operator!=(const base& rhs){return node!=rhs.node;}
};


template<class T,class Hash,class KeyEqual>
struct ht_iterator:public ht_iterator_base<T,Hash,KeyEqual>
{
    typedef ht_iterator_base<T,Hash,KeyEqual>    base;

    typedef typename base::hashtable             hashtable;
    typedef typename base::iteraotr              iterator;
    typedef typedef  base::const_iterator        const_iterator;
    typedef typedef  base::node_ptr              node_ptr;
    typedef typedef  base::contain_ptr           contain_ptr;

    typedef ht_value_traits<T>                   value_traits;
    typedef T                                    pointer;
    typedef T*                                   pointer;
    typedef T&                                   reference;

    using base::ht;
    using base::node;

    ht_iterator()=default;

    ht_iterator(node_ptr n,contain_ptr p)
    {
        node = n;
        ht   = p;
    }

    ht_iterator(const iterator& rhs)
    {
        node = rhs.node;
        ht   = rhs.ht;
    }

    iterator& operator=(const iterator& rhs)
    {
        node = rhs.node;
        ht = rhs.ht;
    }
    ht_iterator(iterator&& rhs)
    :node(rhs.node)
    ,ht(rhs.ht)
    {
        rhs.node = nullptr;
        rhs.ht = nullptr;
    }

    reference operator*(){return node->value;}
    pointer operator->(){return &(node->value);}

    iterator& operator++()
    {
        auto tmp = node;
        node = node->next;
        if(node==nullptr)
        {
            //说明当前迭代器指向一条链表的最后一个元素，此时递增会进入下一个单元
            auto index = ht->hash(value_traits::get_key(node->value));
            while(!node&&++index<ht->bucket_size_)
            {
                node = ht->buckets_[index];
            }
        }
        return *this;

    }
    iterator operator++(int)
    {
        iterator tmp = *this;
        ++*this;
        return tmp;
    }
};

//常量迭代器和普通迭代器的区别在解引用和调用运算符上，解引用返回的是引用、调用运算符返回节点中数据的指针，因此，常量迭代器中他们都要是常量
template<class T,class Hash,class KeyEqual>
struct ht_const_iterator:public ht_iterator_base<T,Hash,KeyEqual>
{
    typedef ht_iterator_base<T,Hash,KeyEqual>    base;
    typedef typename base::hashtable             hasetable;

    typedef typename base::iteraotr              iterator;
    typedef typedef  base::const_iterator        const_iterator;
    typedef typedef  base::node_ptr              node_ptr;
    typedef typedef  base::contain_ptr           contain_ptr;

    typedef ht_value_traits<T>                   value_traits;
    typedef T                                    value_type;
    typedef const value_type&                    reference;
    typedef const value_type*                    pointer;    //底层const,不能通过指针修改所指对象的值


    using base::node;
    using base::ht;
    ht_const_iterator()=default;
    ht_const_iterator(const ht_const_iterator& rhs)
    {
        node = rhs.node;
        ht = rhs.ht;
    }

    ht_const_iterator(const ht_iterator& rhs)
    {
        node = rhs.node;
        ht = rhs.ht;
    }

    ht_const_iterator& operator=(const ht_const_iterator& rhs)
    {
        node = rhs.node;
        ht = rhs.node;
        return *this;
    }

    ht_const_iterator& operator=(const ht_iteartor& rhs)
    {
        node = rhs.node;
        ht = rhs.ht;
        return *this;
    }

    reference operatro*()
    {
        return node->value;
    }

    pointer operator->()
    {
        return &(operator*());
    }

    ht_const_iterator& operator++()
    {
        node_ptr  oldNode = node;
        node = curNode->next;
        if(node==nullptr)
        {
            auto index = ht->hash(value_traits::get_key(oldNode->value));
            while(!node&&index<ht->bucket_size_)
            {
                node= ht->buckets_[index];
                index++;
            }
            
        }
        return *this;
        
    }

    ht_const_iterator operator++(int)
    {
        ht_const_iterator tmp = *this;
        ++*this;
        return tmp;

    }

};


#if(_MSC_VER&&_WIN64)||((__GNUC__||__clang__)&&__SIZEOF_POINTER__==8)
#define SYSTEM_64 1
#else
#define SYSTEM_32 1
#endif

#ifdef SYSTEM_64

#define PRIME_NUM 99

static constexpr size_t ht_prime_list[]={
      101ull, 173ull, 263ull, 397ull, 599ull, 907ull, 1361ull, 2053ull, 3083ull,
  4637ull, 6959ull, 10453ull, 15683ull, 23531ull, 35311ull, 52967ull, 79451ull,
  119179ull, 178781ull, 268189ull, 402299ull, 603457ull, 905189ull, 1357787ull,
  2036687ull, 3055043ull, 4582577ull, 6873871ull, 10310819ull, 15466229ull,
  23199347ull, 34799021ull, 52198537ull, 78297827ull, 117446801ull, 176170229ull,
  264255353ull, 396383041ull, 594574583ull, 891861923ull, 1337792887ull,
  2006689337ull, 3010034021ull, 4515051137ull, 6772576709ull, 10158865069ull,
  15238297621ull, 22857446471ull, 34286169707ull, 51429254599ull, 77143881917ull,
  115715822899ull, 173573734363ull, 260360601547ull, 390540902329ull, 
  585811353559ull, 878717030339ull, 1318075545511ull, 1977113318311ull, 
  2965669977497ull, 4448504966249ull, 6672757449409ull, 10009136174239ull,
  15013704261371ull, 22520556392057ull, 33780834588157ull, 50671251882247ull,
  76006877823377ull, 114010316735089ull, 171015475102649ull, 256523212653977ull,
  384784818980971ull, 577177228471507ull, 865765842707309ull, 1298648764060979ull,
  1947973146091477ull, 2921959719137273ull, 4382939578705967ull, 6574409368058969ull,
  9861614052088471ull, 14792421078132871ull, 22188631617199337ull, 33282947425799017ull,
  49924421138698549ull, 74886631708047827ull, 112329947562071807ull, 168494921343107851ull,
  252742382014661767ull, 379113573021992729ull, 568670359532989111ull, 853005539299483657ull,
  1279508308949225477ull, 1919262463423838231ull, 2878893695135757317ull, 4318340542703636011ull,
  6477510814055453699ull, 9716266221083181299ull, 14574399331624771603ull, 18446744073709551557ull
};

#else

#define PRIME_NUM 44

// 1. start with p = 101
// 2. p = next_prime(p * 1.7)
// 3. if p < (2 << 31), go to step 2, otherwise, go to step 4
// 4. end with p = prev_prime(2 << 31 - 1)
static constexpr size_t ht_prime_list[] = {
  101u, 173u, 263u, 397u, 599u, 907u, 1361u, 2053u, 3083u, 4637u, 6959u, 
  10453u, 15683u, 23531u, 35311u, 52967u, 79451u, 119179u, 178781u, 268189u,
  402299u, 603457u, 905189u, 1357787u, 2036687u, 3055043u, 4582577u, 6873871u,
  10310819u, 15466229u, 23199347u, 34799021u, 52198537u, 78297827u, 117446801u,
  176170229u, 264255353u, 396383041u, 594574583u, 891861923u, 1337792887u,
  2006689337u, 3010034021u, 4294967291u,
};

#endif

//找到大于等于n的最小的质数
inline size_t ht_next_prime(size_t n)
{

}


template<class T,class Hash,class KeyEqual>
class hashtable
{

//内置类型定义
public:
    friend struct mystl::ht_iterator<T,Hash,KeyEqual>;
    friend struct mystl::ht_const_iterator<T,Hash,KeyEqual>;

    typedef ht_value_traits<T>                                value_traits;//萃取
    typedef typename value_traits::key_type                   key_type;    //键类型
    typedef typename value_traits::mapped_type                mapped_type; //值类型
    typedef typename value_traits::value_type                 value_type;  //节点类型（对于map，是pair，对于set跟key_type一样）

    typedef Hash                                              hasher;
    typedef KeyEqual                                          key_equal;

    typedef hashtable_node<T>                                 node_type;//节点类型
    typedef node_type*                                        node_ptr; //节点类型的指针：用于构造迭代器（迭代器可认为是节点类型的指针）
    typedef mystl::vector<node_ptr>                           bucket_type;  //桶（哈希表）

    typedef mystl::allocator<T>                               allocator_type;
    typedef mystl::allocator<T>                               data_allocator;
    typedef mystl::allocator<node_type>                       node_allocator;

    typedef typename allocator_type::size_type                size_type;
private:

    bucket_type    buckets_;  //哈希表，是一段连续地址空间，其内存放了哈希表的节点的指针（哈希冲突的关键字以链表组织起来，哈希表中存储了链表的头节点）
    size_type      bucket_size_;
    size_type      size_;     //已经装入的数据的数量（等于节点数量）
    double         mlf_;     //装填因子
    hasher         hash_;    //哈希函数
    key_equal      equal_;   //关键字的判等函数



public:
    explicit hashtable(size_type bucket_size,const hasher& hash=hasher(),const key_equal& equal = key_equal())
    :bucket_size_(bucket_size)
    ,size(0)
    mlf(0.0)
    ,hash_(hash)
    ,equal_(equal)
    {
        init(bucket_size);
    }

    void init(size_type count)
    {
        //调整到素数
        const auto bucket_num = ht_next_prime(count);
        try
        {
            //预分配空间并初始化
            buckets_.reserve(bucket_num);
            buckets_.assign(bucket_num,nullptr);
        }
        catch(...)
        {
            bucket_size_ = 0;
            size_ = 0;
            throw;
        }
        bucket_size_ = bucket_num;
    }

    //如果Iter是迭代器类型，才会匹配到下面的构造函数
    template<class Iter,typename std::enable_if<mystl::is_input_iterator<Iter>::value,int>::type=0>
    hashtable(
        Iter            first,
        Iter            last,
        size_tyep       bucket_count,
        const Hash      &hash = Hash(),
        const KeyEqual  &equal = KeyEqual())
        {
            init(mystl::max(bucket_count,mystl::distance(first,last)));
        }


    hashtable(const hashtable &rhs)
    :hash_(rhs.hash_)
    ,equal_(rhs.equal_)
    {

    }

    hashtable(hashtable &&rhs)
    :bucket_size_(rhs.bucket_size_)
    ,size_(rhs.size)
    ,mlf_(rhs.mlf)
    hash_(rhs.hash_)
    equal_(rhs.equal_)
    {
        buckets_(mystl::move(rhs.buckets_));
        rhs.bucket_size_ = 0;
        rhs.size_ = 0;
        rhs.mlf_ = 0.0f;
    }


    //赋值运算符
    hashtable& operator=(const hashtable &rhs);
    hashtable& operator=(hashtable &&rhs);

    //析构函数
    ~hashtable();



private:
    void destroy_node(node_ptr curNode);





};

template<class T,class Hash,class KeyEqual>
hashtable<T,Hash,KeyEqual>& 
hashtable<T,Hash,KeyEqual>::operator=(const hashtable &rhs)
{
    buckets_     = rhs.buckets_;
    bucket_size_ = rhs.bucket_size_;
    size_        = rhs.size_;
    mlf_         = rhs.mlf_;
    hash_        = rhs.hash_;
    equal_       = rhs.equal_;

}

template<class T,class Hash,class KeyEqual>
hashtable<T,Hash,KeyEqual>&
hashtable<T,Hash,KeyEqual>::operator=(hashtable &&rhs)
{
    buckets_ = mystl::move(rhs.buckets_);
    bucket_size_ = rhs.bucket_size_;e
    size_ = rhs.size_;
    mlf_ = rhs.mlf_;
    hash_ = rhs.hash_;
    equal_ = rhs.equal_;

    rhs.bucket_size_ = 0;
    rhs.size_ = 0;
    rhs.mlf = 0.0f;
}

template<class T,class Hash,class KeyEqual>
hashtable<T,Hash,KeyEqual>::~hashtable()
{
    for(int i=0;i<bucket_size_;i++)
    {
        if(buckets_[i])
        {
            node_ptr cur = buckets_[i];
            while(cur)
            {
                node_ptr next =cur->next;
                //销毁节点
                destroy_node(cur);
                cur = next;
                
            }
            buckets_[i]=nullptr;
        }
    }
    size_ = 0;
}


template<class T,class Hash,class KeyEqual>
void hashtable<T,Hash,KeyEqual>::destroy_node(node_ptr curNode)
{
    mystl::destroy_one(&curNode->value);
    data_allocator::deallocate(curNode);
    curNode = nullptr;
}


}





#endif