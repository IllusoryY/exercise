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
    void InitStack(int val);
    void Push(int);
    int Pop();
    bool IsEmpty();
    void Print();
    void Delete();
private:
    Node* top;
};

#endif
