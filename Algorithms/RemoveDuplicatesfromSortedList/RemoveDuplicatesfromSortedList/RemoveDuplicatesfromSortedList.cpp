/*
Given a sorted linked list, delete all duplicates such that \
each element appear only once.
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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == nullptr) return head;
		ListNode *slow = head, *fast = slow->next;

		while (fast != nullptr)
		{
			if (slow->val == fast->val)
			{
				slow->next = fast->next;
				delete fast;
				fast = slow->next;
			}
			else
			{
				slow = fast;
				fast = fast->next;
			}
		}

		return head;
	}
};

int main()
{
	ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(1);
	ListNode *ptr2 = new ListNode(3);
	ptrA->next = ptr1;
	ptr1->next = ptr2;

	Solution s;
	ListNode *result = s.deleteDuplicates(ptrA);
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

	system("pause");
	return 0;
}