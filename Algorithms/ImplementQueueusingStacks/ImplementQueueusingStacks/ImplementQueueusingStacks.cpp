/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
*/

#include<stack>
#include<iostream>

using std::stack;

class Queue
{
public:
	Queue(){}
	
	void push(int x)
	{
		in.push(x);
	}

	int peek()
	{
		if (!in.empty() && out.empty())
		{
			while (!in.empty())
			{
				out.push(in.top());
				in.pop();
			}
		}
		return out.top();
	}

	int pop()
	{
		int ans = peek();
		out.pop();
		return ans;
	}

	bool empty()
	{
		return in.empty() && out.empty();
	}

private:
	stack<int> in;
	stack<int> out;
};

int main()
{
	Queue que;
	que.push(1);
	que.push(2);

	std::cout << "队列第一个值为" << que.peek() << std::endl;
	std::cout << que.pop() << std::endl;

	que.push(3);
	std::cout << "队列第一个值为" << que.peek() << std::endl;

	std::cout << (que.empty() ? "队列为空" : "队列不为空")  << std::endl;

	return 0;
}
