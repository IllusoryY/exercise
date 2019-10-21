#include"Stack.h"
#include<iostream>

void Stack::InitStack(int val)
{
    top = new Node();
    top->data = val;
    top->next = nullptr;
}

void Stack::Push(int val)
{
    Node* tmp = new Node();
    tmp->data = val;
    tmp->next = top;
    top = tmp;
}

int Stack::Pop()
{
    if(top)
    {
        int tmp = top->data;
        Node* ptmp = top;
    
        top = top->next;
        delete ptmp;
        return tmp;
    }
    else
    {
        std::cout << "栈为空" << std::endl;
        return -1;
    }
    
}

bool Stack::IsEmpty()
{
    return top == nullptr;
}

void Stack::Delete()
{
    Node* curr = top;
    while(curr)
    {
        top = top->next;
        
        delete curr;
        curr = top;
    }
}
