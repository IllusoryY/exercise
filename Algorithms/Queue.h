class Queue
{
public:
    Queue();
    ~Queue();
    void Dequeue();
    void Enqueue();
    void Print();
    void MakeEmpty();
    bool IsEmpty();
private:
    int capacity_;
    int size_;
    int front_;
    int rear_;
    int arr[];
}
