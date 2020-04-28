/*
725::Given a (singly) linked list with head node root, \
write a function to split the linked list into k consecutive\
linked list "parts".

The length of each part should be as equal as possible: \
no two parts should have a size differing by more than 1. \
This may lead to some parts being null.

The parts should be in order of occurrence in the input list,\
and parts occurring earlier should always have a size greater than or\
equal parts occurring later.

Return a List of ListNode's representing the linked list parts that\
are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
*/
#include<iostream>
#include<vector>

using std::vector;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k)
	{
		vector<ListNode *> lvec(k);
		int count = listLength(root);

		int num = count / k; //判断每个链表分几个元素
		int rem = count % k; //判断是否有链表需要多分配

		ListNode *cutNode = root;
		ListNode *tmp = nullptr;
		int index = 0;
		while (cutNode)
		{
			for (int i = 1; i < num; ++i)
			{
				cutNode = cutNode->next;
			}
			if(rem > 0)
				cutNode = cutNode->next;
			tmp = cutNode->next;
			cutNode->next = nullptr;
			lvec[index] = root;
			++index;
			--rem;
			root = cutNode = tmp;
		}

		return lvec;
	}

	int listLength(ListNode *head)
	{
		int count = 0;
		while (head)
		{
			++count;
			head = head->next;
		}

		return count;
	}
};

void deleteList(ListNode *head)
{
	ListNode *tmp = nullptr;
	while (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}

	std::cout << "链表删除成功" << std::endl;
}

int main()
{
	/*ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ListNode *ptr3 = new ListNode(4);
	ptrA->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;*/

	ListNode *ptrB = new ListNode(5);
	ListNode *ptra = new ListNode(4);
	ListNode *ptrb = new ListNode(3);
	ListNode *ptrc = new ListNode(2);
	ListNode *ptrd = new ListNode(1);
	ptrB->next = ptra;
	ptra->next = ptrb;
	ptrb->next = ptrc;
	ptrc->next = ptrd;

	Solution s;
	vector<ListNode*> result = s.splitListToParts(ptrB, 3);
	for (vector<ListNode*>::size_type ix = 0; ix < result.size(); ++ix)
	{
		while (result[ix])
		{
			std::cout << result[ix]->val << " ";
			result[ix] = result[ix]->next;
		}
		std::cout << std::endl;
	}

	deleteList(ptrB);

	system("pause");
	return 0;
}