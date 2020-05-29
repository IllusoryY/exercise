/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes\
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return root;

		if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
		else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};

void helper(TreeNode* root, vector<int>& vec);
vector<int> pre_order(TreeNode* root)
{
	vector<int> ans;
	helper(root, ans);
	return ans;
}

void helper(TreeNode* root, vector<int>& vec)
{
	if (!root) return;
	vec.push_back(root->val);
	helper(root->left, vec);
	helper(root->right, vec);
}

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(6);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(8);
	//TreeNode *ptr3 = new TreeNode(2);
	//TreeNode *ptr4 = new TreeNode(7);
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->left = ptr1;
	head->right = ptr2;
	//ptr1->right = ptr3;
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
	TreeNode *lhs = root->left;
	TreeNode *rhs = root->right;
	vector<int> ret;
	TreeNode* pt = s.lowestCommonAncestor(root, lhs, rhs);

	cout << pt->val << endl;

	deleteTree(root);
	return 0;
}

