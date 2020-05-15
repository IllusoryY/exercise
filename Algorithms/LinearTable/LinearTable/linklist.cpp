#include"linklist.h"
//拷贝构造函数
template<typename T>
LinkList<T>::LinkList(const LinkList& lhs)
{
	LinkListNode<T>* prl = lhs.head();
	_dummy = new LinkListNode<T>();
	memory_is_full(_dummy);

	LinkListNode<T>* cur = _dummy;
	while (prl)
	{
		LinkListNode<T>* tmp = new LinkListNode<T>(prl->_data);
		memory_is_full(tmp);
		cur->next = tmp;
		cur = cur->next;
		++_size;

		prl = prl->next;
	}
}

//赋值构造函数
template<typename T>
LinkList<T>& LinkList<T>::operator= (LinkList<T>& lhs)
{
	if (!this->is_empty())
		make_empty();

	LinkListNode<T>* prl = lhs.head();
	_dummy = new LinkListNode<T>();
	memory_is_full(_dummy);

	LinkListNode<T>* cur = _dummy;
	while (prl)
	{
		LinkListNode<T>* tmp = new LinkListNode<T>(prl->_data);
		memory_is_full(tmp);
		cur->next = tmp;
		cur = cur->next;
		++_size;

		prl = prl->next;
	}
	return *this;
}

template<typename T>
LinkList<T>::~LinkList()
{
	make_empty();
	delete _dummy;
}

template<typename T>
void memory_is_full(T* item)
{
	if (item == nullptr)
	{
		std::cout << "out of memory" << std::endl;
		exit(-1);
	}
}

template<typename T>
LinkListNode<T>* LinkList<T>::head() const
{
	return _dummy->next;
}

template<typename T>
void LinkList<T>::creat_list(int len)
{
	LinkListNode<T>* tmp = _dummy;

	T *pt = new T[len];
	for (int i = 0; i < len; ++i)
	{
		int j = i + 1;
		std::cout << "请输入要初始化的第：" << j << "个值" << std::endl;
		std::cin >> pt[i];
		LinkListNode<T>* node = new LinkListNode<T>(pt[i]);
		memory_is_full(node);
		++_size;
		tmp->next = node;
		tmp = node;
	}

	delete [] pt;
}

template<typename T>
int LinkList<T>::length() const
{
	return _size - 1;
}

template<typename T>
bool LinkList<T>::is_empty() const
{
	return (_size - 1) == 0;
}

template<typename T>
bool LinkList<T>::insert(T& data, int pos)
{
	LinkListNode<T>* node = new LinkListNode<T>(data);
	memory_is_full(node);
	if (length() == 0)
	{
		_dummy->next = node;
		
	}
	else if (pos > length() || pos < 0)
	{
		std::cout << "插入位置无效" << std::endl;
		return false;
	}
	else
	{
		LinkListNode<T>* pre = _dummy;
		LinkListNode<T>* cur = _dummy->next;
		for (int i = 1; i < pos; ++i)
		{
			pre = cur;
			cur = pre->next;
		}
		node->next = cur;
		pre->next = node;
	}
	++_size;
	return true;
}

template<typename T>
bool LinkList<T>::erase(int pos)
{
	if (pos < 0 || length() < pos)
	{
		std::cout << "该位置元素不存在" << std::endl;
		return false;
	}
	else
	{
		LinkListNode<T>* pre = _dummy;
		LinkListNode<T>* cur = _dummy->next;
		for (int i = 1; i < pos; ++i)
		{
			pre = cur;
			cur = pre->next;
		}
		pre->next = cur->next;
		delete cur;
	}
	--_size;
	return true;
}

template<typename T>
void LinkList<T>::print()
{
	LinkListNode<T>* cur = _dummy->next;
	while (cur)
	{
		std::cout << cur->_data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}

template<typename T>
void LinkList<T>::make_empty()
{
	while (!this->is_empty())
	{
		erase(1);
	}
}

template<typename T>
void LinkList<T>::my_reverse()
{
	if (!this->is_empty())
	{
		LinkListNode<T>* pre = nullptr;
		LinkListNode<T>* cur = this->_dummy->next;
		while (cur)
		{
			LinkListNode<T>* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		_dummy->next = pre;
	}
}

template<typename T>
bool LinkList<T>::is_loop() const
{
	if (!this->is_empty())
	{
		LinkListNode<T>* slow = _dummy;
		LinkListNode<T>* fast = slow->next;
		while (fast && fast->next)
		{
			if (slow == fast)
				return true;
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	return false;
}
