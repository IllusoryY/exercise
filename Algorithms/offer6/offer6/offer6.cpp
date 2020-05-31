/*
题目：从尾到头打印链表
	输入一个链表的头节点，从尾到头反过来打印出每个节点的值
*/

#include <stack>
#include <iostream>
using std::stack;

class ListNode
{
public:
	int val;
	ListNode* next;
};

void reverse_print(ListNode* head)
{
	stack<ListNode*> s;
	while (head)
	{
		s.push(head);
		head = head->next;
	}

	ListNode* tmp = nullptr;
	while (!s.empty())
	{
		tmp = s.top();
		s.pop();
		std::cout << tmp->val << " ";
	}
	std::cout << std::endl;
}