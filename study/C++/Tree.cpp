#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    :val(0)
    ,left(nullptr)
    ,right(nullptr)
    {

    }
    TreeNode(int value)
    :val(value)
    ,left(nullptr)
    ,right(nullptr)
    {

    }
    TreeNode(int value,TreeNode* leftNode,TreeNode* rightNode)
    :val(value)
    ,left(leftNode)
    ,right(rightNode)
    {

    }

};


//前序遍历
void PreTraverse(TreeNode* root)
{
    std::vector<int> res;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* cur = s.top();
        res.push_back(cur->val);
        s.pop();
        if(cur->right)
        {
            s.push(cur->right);
        }
        if(cur->left)
        {
            s.push(cur->left);
        }
    }
}





//中序遍历
void MidTraverse(TreeNode* root)
{
    std::vector<int> res;
    std::stack<TreeNode*> s;
    s.push(root);
    TreeNode* cur = root->left;
    while(!s.empty()||cur)
    {
        if(cur)
        {
            GotoLeft(cur,s);
        }
        cur = s.top();
        res.push_back(cur->val);
        cur = cur->right;
        s.pop();

    }
}

//中序遍历辅助函数
void GotoLeft(TreeNode* root,std::stack<TreeNode*> &s)
{
    while(root)
    {
        s.push(root);
        root = root->left;
    }
}



//后序遍历
void PostTraverse(TreeNode* root)
{
    std::vector<int> res;
    std::stack<TreeNode*> s;
    s.push(root);
    TreeNode* cur = s.top();
    while(!s.empty())
    {
        if(s.top()->left!=cur&&s.top()->right!=cur)
        {
            PostHelp(s);
        }
        cur = s.top();
        res.push_back(cur->val);
        s.pop();


    }
}

//后序遍历辅助函数
void PostHelp(std::stack<TreeNode*> s)
{
    while(TreeNode* cur=s.top())
    {
        if(cur->right)
        {
            s.push(cur->right);
            if(cur->left)
            {
                s.push(cur->left);
            }
        }
        else
        {
            s.push(cur->left);
        }
    }
    s.pop();
}



//二叉搜索树
template<class T>
class Node
{
public:
    typedef T value_type;
    typedef Node* pointer;
    
    value_type m_value;
    pointer    m_left;
    pointer    m_right;

    Node()
    :m_value(0)
    ,m_left(nullptr)
    ,m_right(nullptr)
    {

    }

    Node(value_type value)
    :m_value(value)
    ,m_left(nullptr)
    ,m_right(nullptr)
    {

    }
    Node(value_type value,pointer left,pointer right)
    :m_value(value)
    ,m_left(left)
    ,m_right(right)
    {

    }
    ~Node(){}
};
template<class T>
class BST
{
public:
    typedef Node<T> node_ptr;
    typedef T value_type;

private:
    node_ptr m_root;
public:
    BST();
    ~BST();

    node_ptr search(value_type key,node_ptr &hot);

    void insert(value_type key);

    void erase(value_type key);

};

template<class T>
BST<T>::BST()
{

}


template<class T>
BST<T>::~BST()
{

}


template<class T>
typename BST<T>::node_ptr BST<T>::search(value_type key,node_ptr &hot)
{
    hot=root;
    node_ptr cur = root;
    node_ptr parent = nullpotr;
    while(cur)
    {
        parent = cur;
        if(hot->m_value>key)
        {
            cur = hot->left;
        }
        else if(hot->m_value<key)
        {
            cur = hot->right;
        }
        if(cur->m_value==key)
        {
            break;
        }
        else
        {
            hot = cur;
        }
        
    }
    if(cur==nullptr)
    {
        //沒有找到，此时parent指向最后一个查询的节点
        hot = parent;
    }
    //如果命中，hot指向查询到的节点的父节点
    return cur;
}

template<class T>
void BST<T>::insert(value_type key)
{
    node_ptr hot=nullptr;
    node_ptr res = search(key,hot);
    if(res)
    {
        return;
    }
    if(key>hot->m_value)
    {
        hot->right = new Node<T>(key);
    }
    else
    {
        hot->left = new Node<T>(key);
    }
}

template<class T>
void BST<T>::erase(value_type key)
{
    node_ptr parent = nullptr;
    node_ptr cur = search(key,parent);
    if(node==nullptr)
    {
        //待删除节点不存在
        return;
    }
    //如果不存在右孩子
    if(cur->m_right==nullptr)
    {
        //如果没有右孩子
        if(parent->m_left==cur)
        {
            parent->left==cur->m_left;
        }
        else
        {
            parent->m_right = cur->m_left;
        }
    }
    else
    {
        //找到当前节点的下一个节点（后继）
        node_ptr succ = cur->m_right;
        parent = succ;
        while(succ->m_left)
        {
            parent = succ;
            succ = succ->m_left;
        }
        //交换查询到的节点与其后继节点的值
        swap(cur->m_value,succ->m_value);

        //succ一定没有左孩子节点
        if(parent->m_left==succ)
        {
            parent->m_left = succ->m_right;
        }
        else
        {
            parent->m_right = succ->m_right;
        }
    }



}


//前序遍历

//1递归版本
void PreTraverse(TreeNode* root,std::vector<int> &s)
{
    if(root==nullptr)
    {
        return;
    }
    s.push_back(root->val);
    PreTraverse(root->left,s);
    PreTraverse(root->right,s);
}



//迭代版本
void PreTraverse(TreeNode* root)
{
    if(root==nullptr)
    {
        return;
    }
    std::vector<int> nums;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* cur = s.top();
        s.pop();
        nums.push_back(cur->val);
        if(cur->right)
        {
            s.push(cur->right);
        }
        if(cur->left)
        {
            s.push(cur->left);
        }
    }
}


//中序遍历
//递归版本
void MidTraverse(TreeNode* root,std::vector<int> nums)
{
    if(root==nullptr)
    {
        return ;
    }
    MidTraverse(root->left);
    nums.push_back(root->val);
    MidTraverse(root->right);
}

//迭代版本
void MidTraverse(TreeNode* root,std::vector<int> &nums)
{
    if(root==nullptr)
    {
        return ;
    }
    std::stack<TreeNode*> s;
    s.push(root);
    TreeNode* curNode = root->left;
    while(!s.empty()||curNode)
    {
        if(curNode)
        {
            GotoLeft(curNode,s);
        }
        curNode = s.top();
        s.pop();
        nums.push_back(curNode->val);
        curNode = curNode->right;

    }
}
void GotoLeft(TreeNode* cur,std::stack<TreeNode*> &s)
{
    while(cur)
    {
        s.push(cur);
        cur = cur->left;
    }
}


//后序遍历
//递归版本
void PostTraverse(TreeNode* root,std::vector<int> &nums)
{
    if(root==nullptr)
    {
        return;
    }
    PostTraverse(root->left,nums);
    PostTraverse(root->right,nums);
    nums.push_back(root->val);
}

//迭代版本
void PostTraverse(TreeNode* root,std::vector<int> &nums)
{
    if(root==nullptr)
    {
        return;
    }
    std::stack<TreeNode*> s;
    s.push(root);
    TreeNode* cur = root;
    while(!s.empty())
    {
        if(s.top()->left!=cur&&s.top()->right!=cur)
        {
            PostHelp2(s);
        }
        cur = s.top();
        nums.push_back(cur->val);
        s.pop();
    }

}

void PostHelp2(std::stack<TreeNode*> &s)
{
    while(TreeNode* cur=s.top())
    {
        if(cur->right)
        {
            s.push(cur->right);
            if(cur->left)
            {
                s.push(cur->left);
            }
        }
        else
        {
            s.push(cur->left);
        }
    }
    s.pop();
}

