#pragma once
#include "linklistnode.h"
#include <iostream>

template<typename T>
class LinkList
{
//���캯��
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
	LinkList(const LinkList& lhs);    //�������캯��
	LinkList<T>& operator= (LinkList<T>& lhs); //��ֵ���캯��

	//��������
	~LinkList(); 

//��Ա����
public:
	LinkListNode<T>* head() const;
	void creat_list(int len);   //��������Ϊlen������
	void make_empty();	//�������
	bool is_empty() const;	//�����Ƿ�Ϊ��
	int length() const;	//������
	bool insert(T& data, int pos); //��λ��pos����ڵ�
	bool erase(int pos);	//ɾ��λ��pos�Ľڵ�
	void print();	//��ӡ����
	void my_reverse();	//��ת����
	bool is_loop() const;	//�����Ƿ��л�

private:
	LinkListNode<T>* _dummy;
	int _size = 0;
};   //end class


