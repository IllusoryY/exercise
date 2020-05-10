/*
Given a binary tree, return the inorder traversal of its nodes' values.
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;

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
			ans.push_back(node->val);
			node = node->right;
		}
		return ans;
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(3);
	/*TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);*/
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->right = ptr1;
	ptr1->left = ptr2;
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
	vector<int> ret = s.inorderTraversal(root);

	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	deleteTree(root);

	return 0;
}

