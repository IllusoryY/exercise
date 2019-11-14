class Queue
{
public:
    Queue(int);
    ~Queue();
    void Dequeue();
    void Enqueue(int val);
    void Print();
    void MakeEmpty();
    bool IsEmpty();
private:
    int capacity_;
    int size_;
    int front_;
    int rear_;
    int* arr;
};
