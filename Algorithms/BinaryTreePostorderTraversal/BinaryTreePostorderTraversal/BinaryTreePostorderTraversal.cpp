/*
Given a binary tree, return the postorder traversal of its nodes' values.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

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

		queue<TreeNode*> que;
		if (root)	que.push(root);
		while (!que.empty())
		{
			TreeNode* tmp = que.front();
			que.pop();
			ans.push_back(tmp->val);
			if (tmp->left) que.push(tmp->left);
			if (tmp->right) que.push(tmp->right);
		}

		::std::reverse(ans.begin(), ans.end());

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
	vector<int> ret = s.preorderTraversal(root);

	for (auto i : ret)
		cout << i << " ";
	cout << endl;

	deleteTree(root);
	return 0;
}

