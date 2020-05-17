#include "queue.h"

template<typename T>
my_queue<T>::~my_queue() 
{
	while (!is_empty())
		pop();
}

template<typename T>
int my_queue<T>::size()
{
	return _size;
}

template<typename T>
bool my_queue<T>::is_empty()
{
	return _size == 0;
}

template<typename T>
T& my_queue<T>::front()
{
	if (!is_empty())
		return _front->_data;
	/*else
	{
		//队列为空如何处理
	}*/
}

template<typename T>
T& my_queue<T>::back()
{
	if (!is_empty())
		return _back->_data;
	/*else
	{
		//队列为空如何处理
	}*/
}

template<typename T>
void my_queue<T>::push(const T& data)
{
	LinkListNode<T>* node = new LinkListNode<T>(data);
	if (node == nullptr)
	{
		std::cerr << "out of memory" << std::endl;
		return;
	}

	if (is_empty())
	{
		_front = _back = node;
	}else
	{
		_back->next = node;
		_back = node;
	}
	++_size;
}

template<typename T>
void my_queue<T>::pop()
{
	if (is_empty())
	{
		return;
	}else if(this->size() == 1)
	{
		delete _front;
		_front = _back = nullptr;
	}
	else
	{
		LinkListNode<T>* tmp = _front->next;
		delete _front;
		_front = tmp;
	}
	--_size;
}

template<typename T>
void my_queue<T>::print()
{
	LinkListNode<T>* cur = _front;
	while (cur)
	{
		std::cout << cur->_data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}