/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node \
differ in height by no more than 1.
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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;

		int lhs = maxDepth(root->left);
		int rhs = maxDepth(root->right);
		if (lhs < 0 || rhs < 0 || std::abs(lhs - rhs) > 1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int maxDepth(TreeNode *root)
	{
		if (!root)	return 0;

		return (1 + max(maxDepth(root->left), maxDepth(root->right)));
	}

private:
	int length = 0;
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *ptr1 = new TreeNode(9);
	TreeNode *ptr2 = new TreeNode(20);
	TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);
	TreeNode *ptr5 = new TreeNode(21);
	head->left = ptr1;
	head->right = ptr2;
	ptr2->left = ptr3;
	ptr2->right = ptr4;
	ptr3->left = ptr5;

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

	TreeNode *head = MakeTree();
	cout << (s.isBalanced(head) ? "我是真的" : "我是假的") << endl;

	deleteTree(head);

	return 0;
}

