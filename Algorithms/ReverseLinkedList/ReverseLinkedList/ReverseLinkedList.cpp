/*
Reverse a singly linked list.
*/
#include<iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//note：头节点变为尾节点
class Solution
{
public:
	ListNode* reverseList(ListNode* head) 
	{
		if (head == nullptr || head->next == nullptr) return head;

		ListNode *pre = nullptr, *cur = head, *tmpCell = nullptr;
		while(cur)
		{
			tmpCell = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmpCell;
		}

		return pre;
	}
};

int main() 
{
	ListNode *head = new ListNode(1);
	ListNode *ptr1 = new ListNode(2);
	ListNode *ptr2 = new ListNode(3);
	ListNode *ptr3 = new ListNode(4);
	ListNode *ptr4 = new ListNode(5);
	head->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;
	ptr3->next = ptr4;

	Solution *s = nullptr;
	ListNode *result = s->reverseList(head);

	ListNode *ptr = result;
	while (ptr)
	{
		std::cout << ptr->val << std::endl;
		ptr = ptr->next;
	}

	while (result) 
	{
		ListNode *tmp = result->next;
		delete result;
		result = nullptr;
		result = tmp;
	}

	return 0;
}