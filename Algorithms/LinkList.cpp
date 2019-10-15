#include"LinkList.h"
#include<iostream>

void LinkList::InitLinkList(int n)
{
    if(n < 0)
        std::cout << "请输入想要的节点数" << std::endl;
    else
    {
        for(int i = 1; i <= n; ++i)
            {
                std::cout << "请输入第" << i << "个节点的值" << std::endl;
                int data = 0;
                std::cin >> data;
                InsertNode(i,data); 
            }
    }
}

void LinkList::InsertNode(Position pos, int data)
{

    //插入位置大于链表长度
    int length = Length();
    int index = 0;

    Node* curr = header;
    Node* pre = nullptr;

    Node* tmp = new Node();
    tmp->val = data;
    tmp->next = nullptr;

    if(pos > length)
    {
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = tmp;        
    }
    else
    {
        int index = 0;
        while(curr->next != nullptr)
        {
            ++index;
            if(index == pos)
            {
                tmp->next = curr;
                pre->next = tmp;
                break;
            }
            pre = curr->next;
            curr = pre->next;
        }
    }
}

int LinkList::Length()
{
    Node* curr = header;
    int length = 0;
    
    while(curr->next != nullptr)
    {
        ++length;
        curr = curr->next;
    }

    return length;
}

void LinkList::PrintLinkList()
{
    if(!IsEmpty())
    {
        Node* curr = header->next;
        while(curr != nullptr)
        {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "空链表" << std::endl;
}

bool LinkList::IsEmpty()
{
    return header->next == nullptr;
}

void LinkList::DeleteNode(Position pos)
{
    int length = Length();
   
    if(pos > length)
        std::cout << "删除的节点超出了链表范围" << std::endl;
    else
    {
        Node* curr = header->next;
        Node* pre = header;
        for(int i = 1; i != pos; ++i)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
    }     
}

void LinkList::DeleteLinkList()
{
    while(Length() != 0)
        DeleteNode(1);
}

