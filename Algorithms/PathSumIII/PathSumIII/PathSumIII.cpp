/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf,\
but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are \
in the range -1,000,000 to 1,000,000.
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
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;

		return num_of_sum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}

	int num_of_sum(TreeNode *root, int val)
	{
		if (!root) return 0;
		val -= root->val;
		return (val == 0 ? 1 : 0) + num_of_sum(root->left, val) + num_of_sum(root->right, val);
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(5);
	TreeNode *ptr1 = new TreeNode(4);
	TreeNode *ptr2 = new TreeNode(8);
	TreeNode *ptr3 = new TreeNode(2 );
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
	ptr3->right = ptr7;
	ptr5->right = ptr8;

	return head;
}

// void print_tree(TreeNode *root)
//{
//	if (root != nullptr)
//	{
//		std::cout << root->val << " ";
//		print_tree(root->left);
//		print_tree(root->right);
//	}
//}

int n = 0;

bool deleteTree(TreeNode *root)
{
	if (!root) return true;

	if (root->left == nullptr && root->right == nullptr &&
		root != nullptr) delete root;


	//print_tree(root);
	cout << endl;
	cout << "第" << ++n << "次调用析构函数" << endl;
	return deleteTree(root->left) && deleteTree(root->right);
}

int main()
{
	Solution s;

	TreeNode *root = MakeTree();
	cout << s.pathSum(root, 9)  << endl;

	deleteTree(root);

	return 0;
}

