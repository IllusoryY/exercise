/*
Given two binary trees and imagine that when you put one of \
them to cover the other, some nodes of the two trees are overlapped \
while the others are not.

You need to merge them into a new binary tree. The merge rule is \
that if two nodes overlap, then sum node values up as the new value \
of the merged node. Otherwise, the NOT null node will be used \
as the node of new tree.
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>

using std::max;
using std::cout;
using std::endl;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *lhs, TreeNode *rhs) :val(x), left(lhs), right(rhs) {}
};

class Solution
{
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2) return nullptr;
		if (!t1) return t2;
		if (!t2) return t1;

		TreeNode *tmp = new TreeNode(t1->val + t2->val);
		tmp->left = mergeTrees(t1->left, t2->left);
		tmp->right = mergeTrees(t1->right, t2->right);

		return tmp;
	}

};

void printTree(TreeNode * root)
{
	if (root != nullptr)
	{
		cout << root->val << " ";
		printTree(root->left);
		printTree(root->right);
	}
}

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *ptr1 = new TreeNode(3);
	TreeNode *ptr2 = new TreeNode(2);
	TreeNode *ptr3 = new TreeNode(5);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->left = ptr3;

	return head;
}

TreeNode *MakeTree1()
{
	TreeNode *head = new TreeNode(2);
	TreeNode *ptr1 = new TreeNode(1);
	TreeNode *ptr2 = new TreeNode(3);
	TreeNode *ptr3 = new TreeNode(4);
	TreeNode *ptr4 = new TreeNode(7);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->right = ptr3;
	ptr2->right = ptr4;

	return head;
}

bool deleteTree(TreeNode *root)
{
	if (!root) return true;

	if (root->left == nullptr && root->right != nullptr &&
		root != nullptr) delete root;

	cout << "我是析构函数" << endl;
	return deleteTree(root->left) && deleteTree(root->right);
}

int main()
{
	Solution s;

	TreeNode *root1 = MakeTree();
	TreeNode *root2 = MakeTree1();
	TreeNode *ans = s.mergeTrees(root1, root2);

	printTree(ans);
	cout << endl;

	//析构异常
	deleteTree(ans);
	return 0;
}

