/*
Given a binary tree, you need to compute the length of the\
diameter of the tree. The diameter of a binary tree is the length \
of the longest path between any two nodes in a tree. \
This path may or may not pass through the root.
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
	int diameterOfBinaryTree(TreeNode* root) {
		maxDepth(root);
		return length;
	}

	int maxDepth(TreeNode *root)
	{
		if (!root)	return 0;
		int lhs = maxDepth(root->left);
		int rhs = maxDepth(root->right);
		length = max(length, lhs + rhs);

		return (1 + max(lhs, rhs));
	}

private:
	int length = 0;
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(3);
	TreeNode *ptr3 = new TreeNode(4);
	TreeNode *ptr4 = new TreeNode(5);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->left = ptr3;
	ptr1->right = ptr4;

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
	cout << s.diameterOfBinaryTree(head) << endl;

	deleteTree(head);
	return 0;
}

