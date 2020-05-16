#include"stack.h"
#include<iostream>

template<typename T>
my_stack<T>::my_stack(const my_stack& lhs)
{
	if (!lhs.is_empty())
	{
		LinkListNode<T>* lcur = lhs._top;
		LinkListNode<T>* node = new LinkListNode<T>(lcur->_data);
		if (node == nullptr)
			std::cerr << "out of memory" << std::endl;

		_top = node;
		lcur = lcur->next;

		LinkListNode<T>* cur = _top;
		while (lcur)
		{
			node = new LinkListNode<T>(lcur->_data);
			cur->next = node;
			cur = cur->next;
			lcur = lcur->next;
		}
	}
}


template<typename T>
my_stack<T>::~my_stack()
{
	while (!is_empty())
		pop();
}


template<typename T>
bool my_stack<T>::is_empty() const
{
	return _top == nullptr;
}

template<typename T>
int my_stack<T>::size()
{
	return _cnt;
}

template<typename T>
T& my_stack<T>::top()
{
	if (!is_empty())
	{
		return _top->_data;
	}
	std::cerr << "µ±Ç°Õ»Îª¿Õ" << std::endl;
}

template<typename T>
void my_stack<T>::push(T& data)
{
	LinkListNode<T>* tmp = new LinkListNode<T>(data);
	if (tmp == nullptr)
	{
		std::cerr << "out of memory" << std::endl;
		return;
	}
	if (!is_empty())
	{
		tmp->next = _top;
	}
	_top = tmp;
	++_cnt;
}

template<typename T>
void my_stack<T>::pop()
{
	while(!is_empty())
	{
		LinkListNode<T>* tmp = _top->next;
		delete _top;
		_top = tmp;
		--_cnt;
	}
	
}

template<typename T>
void my_stack<T>::print()
{
	LinkListNode<T>* cur = _top;
	while (cur)
	{
		std::cout << cur->_data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

