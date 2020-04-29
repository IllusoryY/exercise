/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
*/

#include<queue>
#include<iostream>

using std::queue;

class Stack
{
public:
	Stack() {}

	void push(int x)
	{
		que.push(x);
		for (int val = 0; val < que.size() - 1; ++val)
		{
			que.push(que.front());
			que.pop();
		}
	}

	int pop()
	{
		int ans = que.front();
		que.pop();
		return ans;
	}

	int top()
	{
		return que.front();
	}

	bool empty()
	{
		return que.empty();
	}

private:
	queue<int> que;
};


int main()
{
	Stack s;
	s.push(1);
	s.push(2);

	std::cout << "队列第一个值为" << s.top() << std::endl;
	std::cout << s.pop() << std::endl;

	s.push(3);
	std::cout << "队列第一个值为" << s.top() << std::endl;

	std::cout << (s.empty() ? "队列为空" : "队列不为空") << std::endl;

	return 0;
}
