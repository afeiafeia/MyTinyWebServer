
template<typename T>
template<typename V>
void Tree<T>::travPre(Tree* root,V* v)
{
	//递归版本
	if(root==nullptr)
		return;
	v.visit(root);
	travPre(root->left,v);
	travPre(root->right,v);
	
	//迭代版本
	stack<Tree*> s;
	s.push_back(root);
	while(!s.empty())
	{
		Tree* curNode = s.pop();
		v.visit(curNode);
		if(curNode->right!=nullptr)
		{
			s.push_back(curNode->right);
		}
		if(curNode->left!=nullptr)
		{
			s.push_back(curNode->left);
		}
	}
	
}



template<typename T>
template<typename V>
void Tree<T>::travMid(Tree* root,V* v)
{
	//中序遍历：左中右
	//递归版本
	if(root==nullptr)
		return;
	travMid(root->left,v);
	v.visit(root);
	travMid(root->right,v)；
	
	//迭代版本
	stack<Tree*> s;
	s.push_back(root);
	Tree* curNode = root->left;
	while(!s.empty())
	{
		if(curNode)
		{
			GotoLeft(curNode,s);
		}
		
		curNode = s.pop();
		v.visit(curNode);
		curNode = curNode->right;
		
	}
	
	
}
//中序遍历辅助函数
template<typenmae T,typename V>
void GotoLeft(Tree* node,stack<T> &s)
{
    while(node)
	{
		s.push_back(node);
		node = node->left;
	}
}


template<T>
template<V>
void Tree<T>::travPost(Tree* root,V* v)
{
	//后序遍历：左右中
	
	//递归版本
	if(root==nullptr)
		return;
	
	travPost(root->left,v);
	travPost(root->right,v);
	v.visit(root);
	
	//迭代版本
	stack<Tree*> s;
	s.push_back(root);
	while(!s.empty())
	{
		if(s.top()!=root->parent)
			GotoHLVFL(s);
		root = s.pop();
		v.visit(root);
	}
	
	
}
//后序遍历辅助函数
template<typename T,typename V>
void GotoHLVFL(stack<T> &s)
{
	while(Tree* curNode = s.top())
	{
		if(curNode->left)
		{
			if(curNode->right)
				s.push_back(curNode->right);
			s.push_back(curNode->left);
		}
		else
			s.push_back(curNode->right);
	}
	s.pop();//弹出空指针
}