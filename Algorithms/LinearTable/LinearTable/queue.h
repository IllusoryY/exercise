#pragma once
#include "stack.h"

template<typename T>
class my_queue
{
public:
	//构造函数
	my_queue(LinkListNode<T>* lhs = nullptr, LinkListNode<T>* rhs = nullptr, int size = 0):
		_front(lhs), _back(rhs), _size(size){}

	~my_queue();

	//成员函数
	void push(const T& data);
	void pop();
	T& front();
	T& back();
	bool is_empty();
	int size();
	void print();

private:
	LinkListNode<T>* _front;
	LinkListNode<T>* _back;
	int _size;
};