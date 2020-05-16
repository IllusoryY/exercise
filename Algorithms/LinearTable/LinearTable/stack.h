#pragma once
#include"linklistnode.h"

template<typename T>
struct my_stack
{
public:
	//���캯��
	my_stack(LinkListNode<T>* top = nullptr, int cnt = 0):
		_top(top) ,_cnt(cnt){}

	my_stack(const my_stack& lhs);

	~my_stack();

	//��Ա����
	T& top();
	void pop();
	void push(T& data);
	int size();
	bool is_empty() const;
	void print();

private:
	LinkListNode<T>* _top;
	int _cnt;
};