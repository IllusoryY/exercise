/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from\
the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>

using std::cout;
using std::endl;
using std::min;

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
	int minDepth(TreeNode* root) {
		if (!root)  return 0;
		if (!root->left) return minDepth(root->right) + 1;
		if (!root->right) return minDepth(root->left) + 1;

		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *ptr1 = new TreeNode(9);
	TreeNode *ptr2 = new TreeNode(20);
	TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->left = ptr1;
	head->right = ptr2;
	ptr2->left = ptr3;
	ptr2->right = ptr4;
	//ptr2->left = ptr5;
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
	cout << s.minDepth(root) << endl;

	deleteTree(root);
	return 0;
}

