#pragma once
#include "linklistnode.h"
#include <iostream>

template<typename T>
class LinkList
{
//构造函数
public:
	LinkList()
	{
		_dummy = new LinkListNode<T>;
		++_size;
		if (_dummy == nullptr)
		{
			::std::cout << "out of memory" << ::std::endl;
			exit(-1);
		}	
	}

	LinkList(const T& data);
	LinkList(const LinkList& lhs);    //拷贝构造函数
	LinkList<T>& operator= (LinkList<T>& lhs); //赋值构造函数

	//析构函数
	~LinkList(); 

//成员函数
public:
	LinkListNode<T>* head() const;
	void creat_list(int len);   //创建长度为len的链表
	void make_empty();	//清空链表
	bool is_empty() const;	//链表是否为空
	int length() const;	//链表长度
	bool insert(T& data, int pos); //在位置pos插入节点
	bool erase(int pos);	//删除位置pos的节点
	void print();	//打印链表
	void my_reverse();	//翻转链表
	bool is_loop() const;	//链表是否有环

private:
	LinkListNode<T>* _dummy;
	int _size = 0;
};   //end class


