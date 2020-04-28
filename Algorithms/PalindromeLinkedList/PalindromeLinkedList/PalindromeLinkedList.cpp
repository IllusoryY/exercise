/*
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false
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
	bool isPalindrome(ListNode* head)
	{
		if (!head || !head->next) return true;

		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast == nullptr)
			return false;

		ListNode *tmp = slow, *cutNode = slow->next;
		ListNode *cutList = reveseList(cutNode);
		while (cutList)
		{
			if (cutList->val != head->val)
				return false;
			cutList = cutList->next;
			head = head->next;
		}

		return true;
	}

	ListNode* reveseList(ListNode *head)
	{
		ListNode *pre = nullptr, *cur = head;
		while (cur)
		{
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		return pre;
	}
};

int main()
{
	ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ListNode *ptr3 = new ListNode(1);
	ptrA->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;

	Solution s;
	bool result = s.isPalindrome(ptrA);

	std::cout << (result == 1 ? "链表是回文链表" : "不是回文链表") \
			<< std::endl;

	ListNode *tmp = nullptr;
	while (ptrA)
	{
		tmp = ptrA->next;
		delete ptrA;
		ptrA = tmp;
	}

	return 0;
}