#include <vector>
#include <queue>
#include <iostream>
class solution
{





};
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

TreeNode* solve(TreeNode* root,std::vector<std::vector<int>> &b)
{
    int size = b.size();

    for(int i=0;i<size;i++)
    {
        bool isContinue = false;
        std::queue<TreeNode*> q;
        q.push(root);
        int firstVal = b[i][0];
        int secondVal = b[i][1];
        int theOtherVal;
        TreeNode* pNode = root;
        while(!q.empty())
        {
            TreeNode* curTop = q.front();
            
            if(curTop->val==firstVal||curTop->val ==secondVal)
            {
                theOtherVal = curTop->val==firstVal?secondVal:firstVal;
                 //在另一颗子树查找
                TreeNode* localRoot  = NULL;
                q.pop();
                if(q.empty())
                {
                    break;
                }
                else
                {
                    localRoot = q.front();
                }
 
                std::queue<TreeNode*> localQ;
                localQ.push(localRoot);
                while(!localQ.empty())
                {
                    TreeNode* localTop = localQ.front();
                   
                    if(localTop->val==theOtherVal)
                    {
                        //交换
                        int tmp = curTop->val;
                        curTop->val = localTop->val;
                        localTop->val = tmp;

                        TreeNode* curTmpLeft = curTop->left;
                        curTop->left = localTop->left;
                        localTop->left = curTmpLeft;

                        TreeNode* curTmpRight = curTop->right;
                        curTop->right = localTop->right;
                        localTop->right = curTmpRight;
                        isContinue = true;
                        break;
                    }
                    if(localTop->left)
                    {
                        if(localTop->left->val==theOtherVal)
                        {
                            localQ.push(localTop->left);
                        }
                        else
                        {
                            localQ.push(localTop->left);
                        }
                    }
                    if(localTop->right)
                    {
                        if(localTop->right->val==theOtherVal)
                        {
                            localQ.push(localTop->right);
                        }
                        else
                        {
                            localQ.push(localTop->right);
                        }
                    }
                    localQ.pop();
                
                }
                if(isContinue)
                {
                    break;
                }
            }
            if(curTop->left)
            {
                q.push(curTop->left);
            }
            if(curTop->right)
            {
                q.push(curTop->right);
            }
            q.pop();


        }
        if(isContinue)
        {
            continue;
        }
    }

    return root;
}

int main()
{
    //TreeNode* root = new TreeNode(1);
    //root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
//
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
//
    //root->right->left = new TreeNode(6);
    //root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);

    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(3);


    std::vector<std::vector<int>> b = {{5,2},{2,5}};

    solve(root,b);

    std::queue<TreeNode*> resQ;
    resQ.push(root);
    while(!resQ.empty())
    {
        TreeNode* curTop = resQ.front();
        std::cout<<curTop->val<<"   ";
        if(curTop->left)
        {
            resQ.push(curTop->left);
               // curLevelChild++;
        }
        if(curTop->right)
        {
            resQ.push(curTop->right);
               // curLevelChild++;
        }
        resQ.pop();
    }

    return 0;

}