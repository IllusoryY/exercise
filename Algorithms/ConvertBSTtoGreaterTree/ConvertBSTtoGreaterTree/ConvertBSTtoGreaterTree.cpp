/*
Given a Binary Search Tree (BST), convert it to a Greater Tree \
such that every key of the original BST is changed to the original key plus sum\
of all keys greater than the original key in BST.
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
	TreeNode* convertBST(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode* node = root;

		int sum = 0;
		while (!st.empty() || node)
		{
			while (node)
			{
				st.push(node);
				node = node->right;
			}
			node = st.top();
			st.pop();
			node->val += sum;
			sum = node->val;
			node = node->left;
		}
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
	TreeNode *head = new TreeNode(5);
	TreeNode *ptr1 = new TreeNode(2);
	TreeNode *ptr2 = new TreeNode(13);
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
	vector<int> ret;
	TreeNode* pt = s.convertBST(root);

	ret = pre_order(pt);
	for (int i : ret)
		cout << i << " ";
	cout << endl;

	deleteTree(root);
	return 0;
}

