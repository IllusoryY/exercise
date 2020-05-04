/*
Given a binary tree and a sum, determine if the tree has\
a root-to-leaf path such that adding up all the values along\
the path equals the given sum.

Note: A leaf is a node with no children.
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		if (root->left == nullptr && root->right == nullptr && root->val == sum) return true;

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}

};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(5);
	TreeNode *ptr1 = new TreeNode(4);
	TreeNode *ptr2 = new TreeNode(8);
	TreeNode *ptr3 = new TreeNode(11);
	TreeNode *ptr4 = new TreeNode(13);
	TreeNode *ptr5 = new TreeNode(4);
	TreeNode *ptr6 = new TreeNode(7);
	TreeNode *ptr7 = new TreeNode(2);
	TreeNode *ptr8 = new TreeNode(1);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->left = ptr3;
	ptr2->left = ptr4;
	ptr2->right = ptr5;
	ptr3->left = ptr6;
	ptr3->right = ptr2;
	ptr5->right = ptr8;

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

//结果有误待调整
int main()
{
	Solution s;

	TreeNode *root = MakeTree();
	cout << (s.hasPathSum(root, 22) ? "我是真的" : "我是假的") << endl;

	//deleteTree(root);
	system("pause");
	return 0;
}

