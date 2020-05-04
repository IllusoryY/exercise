/*
Invert a binary tree.
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
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return nullptr;

		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		invertTree(root->left);
		invertTree(root->right);
		return tmp;
	}

};

void printTree(TreeNode * root)
{
	if(root != nullptr)
	{
		cout << root->val << " ";
		printTree(root->left);
		printTree(root->right);
	}
}

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
	printTree(head);
	cout << endl;

	s.invertTree(head);
	printTree(head);
	cout << endl;

	deleteTree(head);
	return 0;
}

