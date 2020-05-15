#include"linklist.h"
#include"linklist.cpp"

int main()
{
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

	ilist.my_reverse();
	ilist.print();
	system("pause");
	return 0;
}