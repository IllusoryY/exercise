/*
Given a binary tree, return the preorder traversal of its nodes' values.
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;

		stack<TreeNode*> st;
		if(root)	st.push(root);
		while (!st.empty())
		{
			TreeNode* tmp = st.top();
			st.pop();
			ans.push_back(tmp->val);
			if (tmp->right) st.push(tmp->right);
			if (tmp->left) st.push(tmp->left);
		}

		return ans;
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(3);
	TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->left = ptr1;
	head->right = ptr2;
	ptr1->left = ptr3;
	ptr3->right = ptr4;
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
	vector<int> ret = s.preorderTraversal(root);

	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	deleteTree(root);
	return 0;
}

