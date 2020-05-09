/*
Given a non-empty binary tree, return the average value of the nodes\
on each level in the form of an array.
*/
#include<iostream>
#include<vector>
#include<queue>

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
	int findBottomLeftValue(TreeNode* root) {
		//广度优先搜索  利用先进先出特性
		queue<TreeNode*> st;
		if (root)  st.push(root);

		int val = 0;
		while (!st.empty())
		{
			int n = st.size();
			for (int i = 0; i < n; ++i)
			{
				TreeNode* tmp = st.front();
				st.pop();
				if (i == 0) val = tmp->val;
				if (tmp->left) st.push(tmp->left);
				if (tmp->right) st.push(tmp->right);
			}
		}
		return val;
	}
};

TreeNode *MakeTree()
{
	TreeNode *head = new TreeNode(2);
	TreeNode *ptr1 = new TreeNode(1);
	TreeNode *ptr2 = new TreeNode(3);
	/*TreeNode *ptr3 = new TreeNode(15);
	TreeNode *ptr4 = new TreeNode(7);*/
	//TreeNode *ptr5 = new TreeNode(4);
	//TreeNode *ptr6 = new TreeNode(3);
	head->left = ptr1;
	head->right = ptr2;
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
	int ans = s.findBottomLeftValue(root);

	cout << ans << endl;

	deleteTree(root);
	return 0;
}

