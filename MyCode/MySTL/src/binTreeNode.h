#ifndef MYSTL_BINTREENODE
#define MYSTL_BINTREENODE

namespace mystl
{
    template<typename T>
    class BinTreeNode
    {
        typedef T          value_type;
        typedef T*         pointer;
        typedef T&         reference;
        typedef const T&   const_reference;
        typedef size_type  size_t;

    private:

        //数据
        T value;
        //父子节点
        pointer parent;
        pointer lChild;
        pointer rChild;

        //
        size_t height;

        BinTreeNode();

        BinTreeNode(const value_type value);

        pointer insertAsLC(const_reference ref);

        pointer insertAsRC(const_reference ref);

        template<typename V> void travLevel(BinTreeNode* p,V&  v);
        template<typename V> void travPre(BinTreeNode* p,V&);
        template<typeneme V> void travIn(BinTreeNode* p,V&);
        template<typename V> void travPost(BinTreeNode* p,V&);

        template<typename T,typename V>
        void visitAlongSide(BinTreeNode<T>* p,V &v,stack<T> &s)
        {
            while(p)
            {
                v.visit(v);
                s.push(p->rChild);
                p = p->lChild;
            }
        }




        
        template<typename T,typename V>
        void GotoHLVFL(stack<T> &s)
        {
            while(BinTreeNode<T>* p = s.top())
            {
                if(p->lChild())
                {
                    if(p->rChild)
                    s.push(p->rChild);
                    s.push(p->lChild);
                }
                else
                {
                    s.push(p->rChild);
                }
            }
            s.pop();
        }







    };

    template<typename T>
    BinTreeNode<T>::BinTreeNode()
    :parent(nullptr)
    ,lChild(nullptr)
    ,rChild(nullptr)
    ,height(-1)
    {

    }

    template<typename T>
    BinTreeNode<T>::BinTreeNode(const value_type value)
    :value(value)
    ,parent(&value)
    ,lChild(nullptr)
    ,rChild(nullptr)
    ,height(1)
    {

    }


    template<typename T>
    template<typename V>
    void BinTreeNode<T>::travLevel(BinTreeNode* p,V &v)
    {
        //层次遍历

    }

    template<typename T>
    template<typename V>
    void BinTreeNode<T>::travPre(BinTreeNode* p,V& v)
    {
        //先序遍历：中左右
        //1.递归法
        if(p==nullptr)
        return;

        v.visit(p);
        travPre(p->lChild);
        travPre(p->rChild);

        //2.迭代法
        stack<pointer> s;
        if (p)
        {
            s.push(p);/* code */
        }
        while(!s.empty())
        {
            pointer x = s.pop();
            v.visit(x);

            if(x.rChild!=nullptr)
            {
                s.push(x.rChild)
            }
            if (x.lChild!=nullptr)
            {
                s.push(x.lChild)/* code */
            }
            

        }

        //2.2迭代法的另一种方式
        stack<BinTreeNode<T>> s;
        s.push(this);
        BinTreeNode<T>* x = s.pop();
        while(true)
        {
            visitAlongSide(x,v,s);
            x = s.pop();
            if (s.empty())
            {
                break;/* code */
            }
            

        }

        


    }

    template<typename T>
    template<typename V>
    void BinTreeNode<T>::travPost(BinTreeNode* p,V &v)
    {
        //递归版
        if(p==nullptr)
        return;
        travPost(p->lChild);
        travPost(p->rChild);
        v.visit(p);


        //迭代版
        stack<BinTreeNode<T>*> s;
        if(p)
        s.push(p);
        while(!s.empty())
        {
            if(s.top()!=p->parent)//栈顶节点不是当前节点的父节点（则一定是其右兄），对于其右兄，再去遍历其是否含有子树
            GotoHLVFL(s);
            p = s.pop();
            v.visit(x);
        }
    }



}


#endif