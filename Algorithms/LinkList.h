#ifndef LINKLIST_H__
#define LINKLIST_H__

#include<iostream>
using Position = int;

template<typename T>
class LinkList
{
public:
	LinkList():header(new Node()), length(0)
	{
		header = nullptr; 
		std::cout << "LinkList构造函数" << std::endl;
	}
    ~LinkList() 
    {
        std::cout << "LinkList析构函数，" << std::endl;
        delete header;
            
    }
    
	//在位置X插入值
	void InsertNode(Position pos, T& item)
	{
		if (pos < 0)
		{
			std::cout << "查找元素的索引大于0" << std:endl;
			return;
		}

		Node* node = new Node();
		node->data = item;
		//超出链表长度将新节点插入链表尾部
		if (length < pos)
		{
			Node* current = header;
			while (current->next)
			{
				current = current->next;
			}
			current->next = node;
		}
		else
		{
			for (int i = 1; i < length; ++i) 
			{
				Node* current = header;
				while (current->next) 
				{
					if (pos == i)
					{
						node->next = current->next;
						current->next = node;
						break;
					}
					else
					{
						current = current->next;
					}
				}
			}
		}
	}

    void Print();   //打印链表
    int Length();    //计算链表长度
    bool IsEmpty(); //判断链表是否为空
    void DeleteNode(Position);   //删除位置X的节点
    void Delete();  //删除整条链表

private:
    Node* header; 
	int length;

	struct Node
	{
		T data;
		Node* next;
	};
};

template<typename T>
void LinkList<T>::Print()
{
	if (length)
	{
		Node* current = header;
		while (current->next)
		{
			std::cout << current->data << std::endl;
			current = current->next;
		}
	}
	else
	{
		std::cout << "空链表" << std::endl;
	}
}

template<typename T>
int LinkList<T>::Length() 
{
	return length;
}

template<typename T>
bool LinkList<T>::IsEmpty()
{
	return length == 0;
}

#endif