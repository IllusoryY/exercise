/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, \
only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
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
	ListNode* swapPairs(ListNode* head)
	{
		ListNode *dummy = new ListNode(-1), *pre = dummy;
		dummy->next = head;

		ListNode *tmp;
		while (pre->next && pre->next->next)
		{
			tmp = pre->next;
			pre->next = tmp->next;
			tmp->next = tmp->next->next;
			pre->next->next = tmp;
			pre = tmp;
		}

		ListNode *ans = dummy->next;
		delete dummy;

		return ans;
	}
};

int main()
{
	ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ListNode *ptr3 = new ListNode(4);
	ptrA->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;

	Solution s;
	ListNode *result = s.swapPairs(ptrA);
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
		result = tmp;
	}

	return 0;
}