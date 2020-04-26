#ifndef STACK_H__
#define STACK_H__

struct Node
{
    int data;
    Node* next;
};

class Stack
{
public:
    Stack() : top(nullptr) {}
    ~Stack() {}
    void InitStack(int data);
    void Push(int);
    int Pop();
    bool IsEmpty();
    void Print();
    void Delete();
private:
    Node* top;
};

#endif
