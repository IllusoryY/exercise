#ifndef LINKLIST_H__
#define LINKLIST_H__
//This is exercise code for List
#include<iostream>

using Position = int;
struct Node
{
    int val;
    Node* next;
};

class LinkList
{
public:
    LinkList()
        : header(new Node()) { header->val = 0; header->next = nullptr; }
    ~LinkList() 
    {
        std::cout << "我是LinkList的析构函数，它正在析构我" << std::endl;
        delete header;
            
    }
    void InitLinkList(int n);    //初始化链表
    void InsertNode(Position , int );   //在位置X插入值
    void Print();   //打印链表
    int Length();    //计算链表长度
    bool IsEmpty(); //判断链表是否为空
    void DeleteNode(Position);   //删除位置X的节点
    void Delete();  //删除整条链表
private:
    Node* header; 
};


#endif
