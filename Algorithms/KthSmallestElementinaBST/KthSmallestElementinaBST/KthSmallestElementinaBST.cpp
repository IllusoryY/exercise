/*
Given a binary search tree,\
write a function kthSmallest to find the kth smallest element in it.
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
	int kthSmallest(TreeNode* root, int k) {
		int cnt = 0;

		stack<TreeNode*> st;
		TreeNode* node = root;
		while (!st.empty() || node)
		{
			while (node)
			{
				st.push(node);
				node = node->left;
			}
			node = st.top();
			st.pop();
			++cnt;
			if (cnt == k) return node->val;
			node = node->right;
		}
		return 0;
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *ptr1 = new TreeNode(1);
	TreeNode *ptr2 = new TreeNode(4);
	TreeNode *ptr3 = new TreeNode(2);
	//TreeNode *ptr4 = new TreeNode(7);
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->right = ptr3;
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
	cout << s.kthSmallest(root, 1) << endl;

	deleteTree(root);
	return 0;
}

