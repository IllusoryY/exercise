/*
 *
 *Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 */
#include<iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//注意判断相交的条件
class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (!headA || !headB) return NULL;

		ListNode *curA = headA;
		ListNode *curB = headB;

		while (curA != curB)
		{
			curA = curA ? curA->next : headB;
			curB = curB ? curB->next : headA;
		}
		return curA;
	}
};

int main()
{
	ListNode *headL = new ListNode(3);
	ListNode *heada = new ListNode(2);
	ListNode *headb = new ListNode(4);
	headL->next = heada;
	heada->next = headb;

	ListNode *headR = new ListNode(0);
	ListNode *head1 = new ListNode(9);
	ListNode *head2 = new ListNode(1);
	//ListNode *head3 = new ListNode(2);
	//ListNode *head4 = new ListNode(4);
	headR->next = head1;
	head1->next = head2;
	head2->next = heada;

	Solution s;
	ListNode *result = s.getIntersectionNode(headL, headR);

	if (result != nullptr)
	{
		std::cout << "The intersection Node is: " << result->val << std::endl;
	}

	ListNode *ptrB = headR;
	ListNode *curB;
	while (ptrB != nullptr)
	{
		curB = ptrB->next;
		delete ptrB;
		ptrB = nullptr;
		ptrB = curB;
	}

	delete headL;
	headL = nullptr;

	return 0;
}
