/*
Given a binary tree, check whether it is a mirror of itself \
(ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
	1
   / \
  2   2
   \   \
   3    3
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>

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

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;

		return helper(root->left, root->right);
	}

	bool helper(TreeNode *lhs, TreeNode *rhs)
	{
		if (!lhs && !rhs) return true;
		if (!lhs || !rhs) return false;
		if (lhs->val != rhs->val) return false;

		return helper(lhs->left, rhs->right) && helper(lhs->right, rhs->left);
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(2);
	TreeNode *ptr3 = new TreeNode(3);
	TreeNode *ptr4 = new TreeNode(4);
	TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->left = ptr3;
	ptr1->right = ptr4;
	ptr2->left = ptr5;
	//ptr2->right = ptr6;

	return head;
}

int n = 0;

bool deleteTree(TreeNode *root)
{
	if (root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		cout << "第" << ++n << "次调用析构函数" << endl;
		delete root;
	}
	return true;
}

int main()
{
	Solution s;

	TreeNode *root = MakeTree();
	cout << (s.isSymmetric(root) ? "true" : "false") << endl;

	deleteTree(root);
	return 0;
}

