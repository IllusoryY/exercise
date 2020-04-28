/*
You are given two non-empty linked lists representing two \
non-negative integers. The most significant digit comes first \
and each of their nodes contain a single digit. Add the two numbers \
and return it as a linked list.

You may assume the two numbers do not contain any leading zero, \
except the number 0 itself.
*/
#include<iostream>
#include<stack>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		std::stack<int> s1, s2;
		s1 = insertToStack(l1);
		s2 = insertToStack(l2);

		int sum = 0; int carry_on = 0;
		ListNode *dummy = new ListNode(-1);
		ListNode *head = dummy;
		while (s1.size() || s2.size() || carry_on)
		{
			if (s1.size())
			{
				sum += s1.top();
				s1.pop();
			}
			if (s2.size())
			{
				sum += s2.top();
				s2.pop();
			}

			carry_on = sum / 10;
			ListNode *tmp = new ListNode(sum % 10);
			sum = carry_on;
			head->next = tmp;
			head = tmp;
		}

		ListNode *newHead = dummy->next;
		delete dummy;
		return newHead;

	}

	std::stack<int> insertToStack(ListNode* head)
	{
		std::stack<int> ans;
		while (head)
		{
			ans.push(head->val);
			head = head->next;
		}
		return ans;
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

	std::cout << "Á´±íÉ¾³ý³É¹¦" << std::endl;
}

int main()
{
	ListNode *ptrA = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ListNode *ptr3 = new ListNode(4);
	ptrA->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;

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
	ListNode *result = s.addTwoNumbers(ptrA, ptrB);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}

	deleteList(result);
	deleteList(ptrA);
	deleteList(ptrB);

	return 0;
}