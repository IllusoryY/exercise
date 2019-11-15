#include"Tree.h"

Tree::Tree() : T(nullptr) {}

Tree::~Tree()
{
    //?
}

void Tree::insert(int val)
{
    TreeNode* tmpNode = new TreeNode();
    tmpNode->data = val;
    tmpNode->left = nullptr;
    tmpNode->right = nullptr;

    if(T == nullptr)
        T = tmpNode;
    else
    {
        if(val < T->data)
            insert(T->left);
        else if(val > T->data)
            insert(T->right);
        else
            // 递归终止条件
    }
}
