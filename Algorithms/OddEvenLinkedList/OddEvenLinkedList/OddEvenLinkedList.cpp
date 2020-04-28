/*
Given a singly linked list, group all odd nodes together followed \
by the even nodes. Please note here we are talking about the \
node number and not the value in the nodes.

You should try to do it in place. \
The program should run in O(1) space complexity and O(nodes) time\
complexity.
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
	ListNode* oddEvenList(ListNode* head)
	{
		if (!head || !head->next) return head;

		ListNode *odd = head, *even = head->next;
		ListNode *evenHead = even;

		while (even && even->next)
		{
			odd = odd->next = even->next;
			even = even->next = odd->next;
		}

		odd->next = evenHead;
		return head;
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
	ListNode *result = s.oddEvenList(ptrB);
	while (result)
	{
		std::cout << result->val << std::endl;
		result = result->next;
	}

	deleteList(result);

	return 0;
}