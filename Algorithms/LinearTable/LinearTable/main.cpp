#include"linklist.h"
#include"linklist.cpp"
#include"stack.h"
#include"stack.cpp"
#include"queue.h"
#include"queue.cpp"

int main()
{
	std::cout << "-----------------------------here is linklist test begin-----------------------------" << std::endl;
	LinkList<int> ilist;
	ilist.creat_list(3);

	LinkList<int> iList2(ilist);
	iList2.print();

	LinkList<int> ilist3;
	ilist3 = iList2;
	ilist3.print();

	ilist.print();

	int val = 5;
	ilist.insert(val, 1);
	ilist.print();

	ilist.erase(2);
	ilist.print();

	std::cout << "链表的长度为：" <<ilist.length() << std::endl;
	std::cout << (ilist.is_empty() ? "空链表" : "非空链表") << std::endl;

	ilist.my_reverse();
	ilist.print();
	std::cout << "-----------------------------here is linklist test end-----------------------------" << std::endl;

	std::cout << "-----------------------------here is stack test begin-----------------------------" << std::endl;
	my_stack<int> s;

	int i = 1, j = 2, k = 3;
	s.push(i);
	s.push(j);
	s.push(k);
	s.print();

	my_stack<int> s1(s);
	s1.print();

	std::cout << "stack的大小为：" << s.size() << std::endl;

	std::cout << "栈顶元素的值为：" << s.top() << std::endl;
	while (!s.is_empty())
		s.pop();
	std::cout << (s.is_empty() ? "空栈" : "非空") << std::endl;

	std::cout << "-----------------------------here is stack test end-----------------------------" << std::endl;

	std::cout << "-----------------------------here is queue test begin-----------------------------" << std::endl;
	my_queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.print();

	q.pop();
	q.print();

	std::cout << "queue的大小为：" << q.size() << std::endl;
	std::cout << "队列首元素为：" << q.front() << std::endl;
	std::cout << "队列尾元素为：" << q.back() << std::endl;
	std::cout << (q.is_empty() ? "空队列" : "非空") << std::endl;

	std::cout << "-----------------------------here is queue test end-----------------------------" << std::endl;
	return 0;
}