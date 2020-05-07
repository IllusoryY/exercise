/*
Given two non-empty binary trees s and t, check whether tree t\
has exactly the same structure and node values with a subtree of s\
. A subtree of s is a tree consists of a node in s and all of this \
node's descendants. \
The tree s could also be considered as a subtree of itself.
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

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s) return false;
		if (is_same(s, t)) return true;

		return isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool is_same(TreeNode *root, TreeNode *t)
	{
		if (!root && !t) return true;
		if (!root || !t) return false;
		if (root->val != t->val) return false;

		return is_same(root->left, t->left) && is_same(root->right, t->right);
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *ptr1 = new TreeNode(4);
	TreeNode *ptr2 = new TreeNode(5);
	TreeNode *ptr3 = new TreeNode(1);
	TreeNode *ptr4 = new TreeNode(2);
	TreeNode *ptr5 = new TreeNode(0);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->left = ptr3;
	ptr1->right = ptr4;
	ptr4->left = ptr5;

	return head;
}

TreeNode *MakeTree1()
{
	TreeNode *head = new TreeNode(4);
	TreeNode *ptr1 = new TreeNode(1);
	TreeNode *ptr2 = new TreeNode(2);
	head->left = ptr1;
	head->right = ptr2;

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
	TreeNode *sub = MakeTree1();
	cout << (s.isSubtree(root, sub) ? "true" : "false")  << endl;

	deleteTree(root);
	deleteTree(sub);
	return 0;
}

