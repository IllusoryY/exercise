/*
Given a linked list, \
remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end,\
the linked list becomes 1->2->3->5.

Note:Given n will always be valid.
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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *slow = head, *fast = head;
		ListNode *tmp;

		for (int ix = 0; ix < n; ++ix)
		{
			fast = fast->next;
		}

		if (fast == nullptr)
		{
			tmp = head->next;
			delete head;
			return tmp;
		}

		while (fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}

		tmp = slow->next;
		slow->next = tmp->next;
		delete tmp;

		return tmp;
	}
};

int main()
{
	ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ptrA->next = ptr1;
	ptr1->next = ptr2;

	Solution s;
	ListNode *result = s.removeNthFromEnd(ptrA, 3);
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