/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest\
path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.
*/
#include<iostream>
#include<algorithm>

using std::max;
using std::cout;
using std::endl;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :val(0), left(nullptr),right(nullptr){}
	TreeNode(int x):val(x), left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode *lhs, TreeNode *rhs):val(x), left(lhs), right(rhs){}
};

class Solution
{
public:
	int maxDepth(TreeNode* root) {
		//终止条件
		if (!root) return 0;

		return (1 + max(maxDepth(root->left), maxDepth(root->right)));
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *ptr1 = new TreeNode(9);
	TreeNode *ptr2 = new TreeNode(20);
	TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);
	head->left = ptr1;
	head->right = ptr2;
	ptr2->left = ptr3;
	ptr2->right = ptr4;

	return head;
}

int n = 0;

bool deleteTree(TreeNode *root)
{
	if (root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		cout << "第" << ++n << "次调用析构函数删除节点" << root->val << endl;
		delete root;
	}
	return true;
}

int main()
{
	Solution s;

	TreeNode *head = MakeTree();
	int ans = s.maxDepth(head);

	deleteTree(head);
	cout << ans << endl;
	return 0;
}

