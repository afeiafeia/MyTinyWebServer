#ifndef MYSTL_RB_TREE_H
#define MYSTL_RB_TREE_H

#include <type_traits>

namespace mystl
{
    enum rb_tree_color_type
    {
        Red,
        Black
    };

    template<typename T> class rb_tree_node;//前置声明

    template<typename T,bool>
    struct rb_tree_value_traits_imp
    {
        typedef T key_type;
        typedef T mapped_value;
        typedef T value_type;

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


    template<typename T>
    struct rb_tree_value_traits_imp<T,true>
    {
        //remove_cv用于去除类型的const、violate限定
        typedef typename std::remove_cv<typename T::first_type>::type key_type;
        typedef typename T::second_type                               mapped_type;
        typedef T                                                     value_type;

        template <class Ty>
        static const key_type& get_key(const Ty& value)
        {
          return value.first;
        }

        template <class Ty>
        static const value_type& get_value(const Ty& value)
        {
          return value;
        }
    };

    template<typename T>
    struct rb_tree_value_traits
    {
        static constexpr bool is_map = mystl::is_pair<T>::value;//这里使用constexpr是因为对于模板的非类型参数，实参一定要是一个常量表达式
        typedef rb_tree_value_traits_imp<T,is_map>  value_traits_type;
        typedef typename value_traits_type::key_type key_type;
        typedef typename value_traits_type::mapped_type mapped_type;
        typedef typename value_traits_type::value_type value_type;

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

    template<class T>
    struct rb_tree_node_traits
    {
        typedef rb_tree_color_type         color_type;
        typedef rb_tree_value_traits<T>    value_traits;

        typedef typename value_traits::key_type      key_type;
        typedef typename value_traits::mapped_type   mapped_type;
        typedef typename value_traits::value_type    value_type;

        typedef rb_tree_node_base<T>* base_ptr;
        typedef rb_tree_node<T>*      node_ptr;

    };

        template<typename T>
        class rb_tree_base_node
        {
        public:
            typedef rb_tree_color_type    color_type;
            typedef rb_tree_base_node<T>* base_ptr;
            typedef rb_tree_node<T>*      node_ptr;

            base_ptr    parent;
            base_ptr    left;
            base_ptr    right;
            color_type  color;


            base_ptr get_base_ptr()
            {
                return &(*this);
            }
            node_ptr get_node_ptr()
            {
                return static<node_ptr>(*this);
            }
        };

        template<typename T>
        class rb_tree_node:public rb_tree_base_node<T>
        {
            typedef rb_tree_base_node<T>* base_ptr;
            typedef rb_tree_node<T>*      node_ptr;

            T value;
            base_ptr get_base_ptr()
            {
                return static<base_ptr>(*this);
            }

            node_ptr get_node_ptr()
            {
                return &*this;
            }

        };




    //迭代器设计
    template<class T>
    struct rb_tree_iterator_base
    {
        typedef typename rb_tree_traits<T>::base_ptr base_ptr;

        base_ptr node;//指向节点自身

        rb_tree_iterator_base()
        :node(nullptr)
        {

        }

        rb_tree_iterator_base(base_ptr x)
        :node(x)
        {}

        void inc()
        {
            if(node==nullptr)
            return;

            if(node->right!=nullptr)
            {
                node=node->right;
                while(node->left)
                {
                    node = node->left;
                }

            }
            else if(is_rb_tree_lChild(node))
            {
                node = node->parent
            }
            else if(is_rb_tree_rChild(node))
            {
                node = node->parent;
                while(is_rb_tree_rChild(node))
                {
                    node = node->parent;
                }
            }
            else
            {
                node=nullptr;
            }
        }

        void dec()
        {
            if(node==nullptr)
            return;

            if(node->left!=nullptr)
            {
                node = node->left;
                while(node->right)
                {
                    node=node->right;
                }
            }
            else if(is_rb_tree_lChild(node))
            {
                node = node->parent;
                while(is_rb_tree_lChild(node))
                {
                    node = node->parent;
                }
            }
            else if(is_rb_tree_rChild(node))
            {
                //当前节点为右孩子节点且左子树为空

                node = node->parent;
            }
            else
            {
                //说明是根节点
                node = nullptr;
            }
        }

    };



    template <class T>
    struct rb_tree_traits
    {
      typedef rb_tree_value_traits<T>            value_traits;

      typedef typename value_traits::key_type    key_type;
      typedef typename value_traits::mapped_type mapped_type;
      typedef typename value_traits::value_type  value_type;

      typedef value_type*                        pointer;
      typedef value_type&                        reference;
      typedef const value_type*                  const_pointer;
      typedef const value_type&                  const_reference;

      typedef rb_tree_base_node<T>               base_type;
      typedef rb_tree_node<T>                    node_type;

      typedef base_type*                         base_ptr;
      typedef node_type*                         node_ptr;
    };

    template<class T>
    struct rb_tree_iterator:public rb_tree_iterator_base<T>
    {

        typedef rb_tree_traits<T>    tree_traits;
        typedef typename tree_traits::key_type key_type;
        typedef typename tree_traits::mapped_type mapped_type;
        typedef typename tree_traits::value_type value_type;

        typedef typename tree_traits::base_ptr base_ptr;
        typedef typename tree_traits::node_ptr node_ptr;

        typedef rb_tree_iterator<T> iterator;
        typedef typename tree_traits::pointer   pointer;

        typedef typename tree_traits::reference reference;


        rb_tree_iterator(){}

        rb_tree_iterator(base_ptr x) 
        :rb_tree_iterator_base(x)
        {}

        rb_tree_iterator(node_ptr y)
        :rb_tree_iterator_base(y)
        {}
        
        reference operator*()
        {
            return node->get_node_ptr->value;
        }

        pointer operator->()
        {
            return &(operator*());
        }


        self& operator++()
        {
            this->inc();
            return *this;
        }

        self operator++(int)
        {
            self tmp(*this);
            ++(*this);
            return tmp;
        }

        self& operator--()
        {
            this->dec();
            return *this;
        }

        self operator--(int)
        {
            self tmp(*this);
            --(*this);
            return tmp;
        }


    };



    //树操作算法

    //最小节点
    template<typename NodePtr>
    NodePtr rb_tree_min(NodePtr curRoot)
    {
        NodePtr minChild = curRoot;
        while(minChild->left!=nullptr)
        {
            node=minChild->left;
        }
        return minChild;

    }

    //最大节点
    template<typename NodePtr>
    NodePtr rb_tree_max(NodePtr curRoot)
    {
        NodePtr maxChild = curRoot;
        while(maxChild->right)
        {
            maxChild = maxChild->right;
        }
        return maxChild;
    }


    template<typename NodePtr>
    bool is_rb_tree_lChild(NodePtr curNode)
    {
        if(curNode->parent==nullptr)
        return false;
        else
        return curNode->parent->left==curNode;
    }

    template<typename NodePtr>
    bool is_rb_tree_rChild(NodePtr curNode)
    {
        if(curNode->parent==nullptr)
        return false;
        else
        return curNode->parent->right==curNode;
    }

    template<typename NodePtr>
    void rb_tree_set_red(NodePtr node)
    {
        node->color = rb_tree_color::Red;
    }

    template<typename NodePtr>
    void rb_tree_set_black(NodePtr node)
    {
        node->color = rb_tree_color::Black;
    }

    template<typename NodePtr>
    bool is_black(NodePtr node)
    {
        return node==nullptr||node->color==rb_tree_color_type::Black
    }

    template<typename NodePtr>
    bool is_red(NodePtr node)
    {
        return !is_black();
    }

    template<typename NodePtr>
    NodePtr rb_tree_next(NodePtr& ptr)
    {
        if(ptr->right!=nullptr)
        return rb_tree_min(ptr);
        while(is_rb_tree_rChild(ptr))
        ptr = ptr->parent;
        return ptr->parent;
    }

    /*---------------------------------------*\
    |       p                         p       |
    |      / \                       / \      |
    |     x   d    rotate left      y   d     |
    |    / \       ===========>    / \        |
    |   a   y                     x   c       |
    |      / \                   / \          |
    |     b   c                 a   b         |
    \*---------------------------------------*/
    //逆时针旋转Node
    template<typename NodePtr>
    NodePtr rb_tree_zag(NodePtr node,NodePtr root)
    {
        auto rChild = node->right;
        auto parent = node->parent;
        rChild->parent = parent;
        if(node==root||parent==nullptr)
        {
            root = rChild;
        }
        else if(is_rb_tree_lChild(node))
        {
            parent->left = rChild;
        }
        else
        {
            parent->right = rChild;
        }
        node->right = rChild->left;
        if(rChild->left!=nullptr)
        {
            rChild->left->parent = node;
        }

        rChild->left = node;
        node->parent = rChild;

        //返回旋转后的局部子树的最高节点
        return rChild;


    }


    /*----------------------------------------*\
    |     p                         p          |
    |    / \                       / \         |
    |   d   x      rotate right   d   y        |
    |      / \     ===========>      / \       |
    |     y   a                     b   x      |
    |    / \                           / \     |
    |   b   c                         c   a    |
    \*----------------------------------------*/
    //顺时针旋转node:node一定是左节点
    template<typename NodePtr>
    NodePtr rb_tree_zig(NodePtr node,NodePtr root)
    {
        auto lChild = node->left;
        auto parent = lChild->parent;
        if(parent==nullptr)
        {
            root = lChild;
        }
        else if(is_rb_tree_rChild(node))
        {
            parent->right = lChild;
        }
        else
        {
            parent->left = lChild;
        }

        lChild->parent = parent;
        node->left = lChild->right;
        if(lChild->right!=nullptr)
        {
            lChild->right->parent = node;
        }
        lChild->right = node;
        node->parent = lChild;

        return lChild;
    }


    //插入节点导致五种情况
    //case 1:新增节点位于根节点，直接令新增节点的颜色为黑即可//说明是新创建红黑树
    //case 2:新增节点的父节点为黑，此时没有破坏平衡条件，不用调整
    //case 3:新增节点的父节点、叔叔节点均为红，令父节点和叔叔节点为黑，祖父节点为红，
    //       然后令祖父节点为当前节点，继续处理
    //case:4:新增节点的父节点为红，叔叔节点为空Null或者黑，父节点是左（右）孩子，当前节点为右（左）孩子，
    //       令父节点为当前节点，以当前节点为指点进行逆时针（顺时针）旋转，此时case 4转换成了case 5
    //case 5:新增节点的父节点为红，叔叔节点为空Null或者黑色，父节点是左（右）孩子，当前节点是左（孩子），
    //       令父节点变为黑色，祖父节点变为红色，以祖父节点为支点进行顺时针（逆时针）旋转
    template<typename T>
    void rb_tree_insert_reblance(NodePtr x,NodePtr root)
    {
        rb_tree_set_red(x);
        while(x!=root)
        {
            auto parent = x->parent;
            //case 2 
            if(is_black(parent))
            {
                break;
            }
            else
            {
                NodePtr uncle = nullptr; 
                //父节点是红色:说明x->parent一定不是根节点，因此x->parent->parent不为空
                if(is_rb_tree_rChild(parent))
                {
                    //叔叔节点为右孩子
                    uncle = parent->parent->right;
                }
                else
                {
                    //叔叔节点为左孩子
                    uncle = parent->parent->left;
                }
                if(uncle&&uncle->color==rb_tree_color::Red)
                {
                    //if(uncle->color==rb_tree_color::Red)
                    //{
                        //case 3
                        rb_tree_set_black(parent);
                        rb_tree_set_black(uncle);
                        rb_tree_set_red(parent->parent);
                        x = parent->parent;
                        continue;
                    //}
                }
                else
                {
                    //case 4或者case 5
                    if(is_rb_tree_lChild(parent))
                    {
                        if(is_rb_tree_rChild(x))
                        {
                            //case 4
                            x = parent;
                            rb_tree_zag(x,root);
                        }

                        rb_tree_set_black(x->parent);
                        rb_tree_set_red(x->parent->parent);
                        rb_tree_zig(x->parent->parent,root);
                        break;


                    }

                    else
                    {
                        //对称情况
                        if(is_rb_tree_lChild(x))
                        {
                            //case 4
                            x = parent;
                            rb_tree_zig(x,root);
                        }

                        rb_tree_set_black(x->parent);
                        rb_tree_set_red(x->parent->parent);
                        rb_tree_zig(x->parent->parent,root);
                        break;
                    }

                }





            }
        }
        rb_tree_set_black(root);
    }


    template<typename NodePtr>
    void rb_tree_erase_rebalance(NodePtr z,NodePtr& root,NodePtr& leftMost,NodePtr& rightMost)
    {
        //z是找到的待删除的节点

        //删除操作分成两步：（1）调整节点、（2）调整颜色
        //（1）首先要进行删除之前的树的节点调整
        auto y = z->left==nullptr||z->right==nullptr?z:rb_tree_next(z);//如果y!=z,则y一定在z的右子树一侧
        auto x = y->left!=nullptr?y->left:y->right;

        auto xp = nullptr;
        //case 1:如果z是单分支（没有左子树或者没有右子树），如果z是根节点，直接将子树节点当做根节点，否则，直接将存在的那个子树给z的父节点
        //case 1:
        if(z->left==nullptr||z->right==nullptr)
        {
            if(x)
            x->parent = z->parent;
            xp = x->parent;

            if(z==root)
            {
                root = x;
            }
            else if(is_rb_tree_rChild(z))
            {
                z->parent->left = x;
            }
            else
            {
                z->parent->right = x;
            }


        }
        //case 2:z既存在左子树，又存在右子树，找到z的下一个节点y，交换y和z的位置和颜色，y变为待删除节点，而且情况转成了case1，
        else
        {
            //交换y和z的位置
            z->left->parent = y;
            y->left = z->left;

            xp = y->parent;
            if(y==z->right)
            {
                if(z==root)
                root=y;
                else if(is_rb_tree_lChild(z))
                {
                    z->parent->left = y;
                }
                else
                {
                    z->parent->right = y;
                }
                y->parent = z->parent;
            }
            else
            {
                //y一定是z的右子树的左子树的一个左节点，而且y没有左子树
                auto x = y->right;//可能为空
                z->right->parent = y;
                y->right = z->right;
                if(x)
                {
                    y->parent->left = x;
                    x->parent = y->parent;
                }
                if(z==root)
                root = y;

                y->parent = z->parent;

            }


            rb_tree_color_type tmpColor = z->color;
            z->color = y->color;
            y->color = tmpColor;
        }

        
        //（2）在调整完点的位置后，z应该与y互换位置，但这里只是将y移动到z的位置并将颜色改为z的颜色
        //实际上,上步没有改变z的位置，因为调整颜色时实际需要的是原y的颜色（与z交换后变成z的颜色了），
        //x为替代者，从x处开始调整颜色（中间根据具体情况可能在某些节点旋转），具体分为一下几种情况（以x为左子树为例，右子树是对称情况）：
        //case 1:如果z是红色，调整位置之后树已经平衡，不需要再调整
        //case 2:如果z是黑色，兄弟节点是黑色且兄弟节点的右子节点为红色，令兄弟节点为父节点的颜色，父节点为黑色，兄弟节点的右子节点为黑色，以父节点为支点进行左旋，调整完成
        //case 3:如果z是黑色，兄弟节点是黑色且兄弟节点的两个孩子是黑色或者Null，父节点是红色，则将兄弟节点变为红色，父节点变为黑色，调整完成
        //case 4:如果z是黑色，兄弟节点是黑色且兄弟节点的两个孩子是黑色或者Null，父节点为黑色，令兄弟节点为红，父节点作为当前节点，继续迭代
        //case 5:如果z是黑色，兄弟节点是红色，令父节点为红，令兄弟节点为黑，以父节点为支点进行左旋，仍以x为当前点，此时case转变为了case2或case3,再调整一次即可

        //如果z（z一定是不空的）、x都是黑色（无论x是否为空），父节点必有非空的另一子节点（兄弟节点），否则的话，根节点到任一外部节点的黑节点数目不满足要求
        //在case 2/3/4/5情况下（双黑情况：z和兄弟都是黑色），兄弟节点一定不为空
        if(is_red(z)                                                                                                                                                                                                                                                                                                                                                                                                                                                                     )
        {
            while(x!=root&&is_black(x))
            {
                if(x==xp->left)
                {
                    //x是左孩子节点,brother是右节点
                    auto brother = xp->right;
                    //case 5:先转变为case 2或者case 3
                    if(is_red(brother))
                    {
                        rb_tree_set_red(xp);
                       //这里不需要判断brother是否为空，一定不为空
                        rb_tree_set_black(brother);  
                        auto curRoot = rb_tree_zag(xp);
                        //重新记录节点（此处x还是原来的值）
                        x = curRoot->left->left;
                        xp = x->parent;
                        brother = xp->right;

                        
                    }
                    //从此处开始，brother一定是黑色了
                    //case 2:  有红色的子节点，令兄弟节点为父节点的颜色，父节点为黑色，兄弟节点的右子节点为黑色，以父节点为支点进行左旋，调整完成
                    
                    //case 2.1存在不为外部节点的兄弟节点且有红色的子节点
                    if(is_red(brother->right))
                    {
                        /*----------------------------------------*\
                        |     p                         p          |
                        |    /  \                       / \         |
                        |   d    xp      rotate right   d   y        |
                        |      /  \     ===========>      / \       |
                        |   z(x)   bro                     b   x      |
                        |    /     / \                           / \     |
                        |   x     tl  tr                         c   a    |
                        \*----------------------------------------*/
                        //右孩子节点为红，与父节点一致均为右节点，以父节点为支点旋转一次即可
                        auto curRoot = rb_tree_zag(xp);
                        //此时brother变为旋转子树的根节点，xp为当前根节点的左孩子节点

                        //原右节点变为黑色
                        rb_tree_set_black(brother->right);

                        //case 2.2原兄弟节点设置为父节点的颜色
                        if(is_red(xp))
                        {
                            rb_tree_set_red(brother);
                        }
                        else
                        {
                            rb_tree_set_black(brother);
                        }

                        //更新节点的位置
                        xp = curRoot->left;
                        x = xp->left;
                        brother = xp->right;
                        //case 2.3:父节点设为黑色
                        rb_tree_set_black(xp);
                    }
                    else if(is_red(brother->left))//此处使用else if表示：如果两个子节点都是红色，按照右节点是红色的处理即可
                    {
                        //左孩子节点为红:需要两次旋转，第一次以兄弟节点为支点进行顺时针（zig）旋转，第二次以父节点为支点进行反方向（逆时针zag）旋转
                        rb_tree_zig(brother);
                        rb_tree_zag(xp);
                        //case 2.2左节点设置为父节点的颜色
                        if(is_red(xp))
                        {
                            rb_tree_set_red(brother);
                        }
                        else
                        {
                            rb_tree_set_black(brother);
                        }
                        //case 2.3:父节点设为黑色
                        rb_tree_set_black(xp);
                    }
                    


                    

                    
                    //if(is_black(brother->left)&&is_black(brother->right))
                    else 
                    {
                        //兄弟节点的两个孩子都是黑色，此时根据父节点颜色又分成两种情况
                        if(is_red(xp))
                        {
                            //case 3：父节点是红色，只需进行两次染色即可：兄弟节点变为红色，父节点变为黑色
                            rb_tree_set_red(brother);
                            rb_tree_set_black(xp);
                        }
                        else
                        {
                            //case 4：父节点是黑色，进行一次染色然后需要迭代
                            rb_tree_set_red(brother);
                            x = xp;
                            xp=xp->parent;
                        }
                    }             
                
                }
                else
                {
                    //替代节点x是右孩子，兄弟节点是左孩子，按照对此情况处理
                }
            }

            if(x)
            {
                rb_tree_set_black(x);
            }
        }



        






    }




//红黑树模板
template<class T,class Compare>
class rb_tree
{
    public:
    
}















}



#endif