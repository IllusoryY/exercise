#include"linklist.h"
#include"linklist.cpp"
#include"stack.h"
#include"stack.cpp"

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

	std::cout << "����ĳ���Ϊ��" <<ilist.length() << std::endl;
	std::cout << (ilist.is_empty() ? "������" : "�ǿ�����") << std::endl;

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

	std::cout << "stack�Ĵ�СΪ��" << s.size() << std::endl;

	std::cout << "ջ��Ԫ�ص�ֵΪ��" << s.top() << std::endl;
	while (!s.is_empty())
		s.pop();
	std::cout << (s.is_empty() ? "��ջ" : "�ǿ�") << std::endl;

	std::cout << "-----------------------------here is stack test end-----------------------------" << std::endl;
	system("pause");
	return 0;
}