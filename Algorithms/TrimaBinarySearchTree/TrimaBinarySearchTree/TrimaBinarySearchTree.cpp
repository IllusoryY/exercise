/*
Given a binary search tree and the lowest and highest boundaries \
as L and R, trim the tree so that all its elements lies in\
[L, R] (R >= L). You might need to change the root of the tree, \
so the result should return the new root of the trimmed binary search tree.
*/
#include<iostream>
#include<vector>
#include<stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

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
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (!root) return nullptr;

		if (root->val < L) return trimBST(root->right, L, R);
		if (root->val > R) return trimBST(root->left, L, R);
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
};

void helper(TreeNode* root, vector<int>& ivec);
vector<int> pre_order(TreeNode* root)
{
	vector<int> ans;
	helper(root, ans);
	return ans;
}

void helper(TreeNode* root, vector<int>& ivec)
{
	if (!root) return;
	ivec.push_back(root->val);
	helper(root->left, ivec);
	helper(root->right, ivec);

}

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(0);
	/*TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);*/
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->right = ptr1;
	head->left = ptr2;
	/*ptr2->left = ptr3;
	ptr2->right = ptr4;*/
	/*ptr2->left = ptr5;
	ptr2->right = ptr6;*/

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
	int lhs = 1, rhs = 2;
	TreeNode* ret = s.trimBST(root,lhs, rhs);

	vector<int> ans = pre_order(ret);
	for (auto a : ans)
		cout << a << " ";
	cout << endl;

	deleteTree(root);
	return 0;
}