/*
��Ŀ����β��ͷ��ӡ����
	����һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ
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