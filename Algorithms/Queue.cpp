#include"Queue.h"
#include<iostream>

Queue::Queue(int capacity = 10) : size_(0), capacity_(capacity), front_(0), rear_(0)
{
    arr = new int[capacity_];
}

Queue::~Queue()
{
    if(arr)
        delete [] arr;
}

void Queue::Dequeue()
{
    if(size_ < 0)
        std::cout << "空队列" << std::endl;
    else
    {
        --size_;
        ++front_;
    }
}

void Queue::Enqueue(int val)
{
    if(capacity_ == size_)
        std::cout << "队列已满" << std::endl;
    else
    {
       ++size_;
       arr[rear_++] = val; 
    }
}

void Queue::Print()
{
    if(IsEmpty())
        std::cout << "空队列" << std::endl;
    else
    {
        for(int begin = front_; begin < rear_ ; ++begin)
            std::cout << arr[begin] << " ";
        std::cout << std::endl;
    }
}

bool Queue::IsEmpty()
{
    return size_ == 0;
}

void Queue::MakeEmpty()
{
    size_ = 0;
    front_ = -1;
    rear_ = -1;
}


int main()
{
    Queue l;
    l.Enqueue(1);
    l.Enqueue(2);
    l.Enqueue(3);
    l.Print(); // 1 2 3

    l.Dequeue(); 
    l.Print(); // 2 3
    
    std::cout << (l.IsEmpty() ? "空队列" : "非空队列") << std::endl;

    l.MakeEmpty();
    l.Print();
}
