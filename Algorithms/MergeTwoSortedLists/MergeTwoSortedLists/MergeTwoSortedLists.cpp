/*
Merge two sorted linked lists and return it as a new list.\
The new list should be made by splicing together the nodes \
of the first two lists.
*/
#include<iostream>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr)	return l2;
		if (l2 == nullptr)	return l1;

		ListNode *head = nullptr;
		if (l1->val < l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}

		ListNode *ptr = head;
		while(l1 && l2)
		{
			if (l1->val < l2->val)
			{
				ptr->next = l1;
				l1 = l1->next;
			}
			else
			{
				ptr->next = l2;
				l2 = l2->next;
			}
			ptr = ptr->next;
		}

		if (l1) { ptr->next = l1; }
		else
		{
			ptr->next = l2;
		}
		return head;
	}
};

int main()
{
	ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ptrA->next = ptr1;
	ptr1->next = ptr2;

	ListNode *ptrB = new ListNode(4);

	Solution s;
	ListNode *result = s.mergeTwoLists(ptrA, ptrB);
	while (result) 
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}

	ListNode *tmp = nullptr;
	while (result) 
	{
		tmp = result->next;
		delete result;
		result = nullptr;
		result = tmp;
	}

	return 0;
}