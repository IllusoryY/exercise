/*
Design a stack that supports push, pop, top, \
and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include<iostream>
#include<stack>

//待完成
using std::stack;

class MinStack
{
	MinStack()
	{

	}

	void push(int x)
	{
		if (minS.empty() || x < minS.top())	minS.push(x);
		stc.push(x);

	}

	void pop()
	{
		if (stc.top() == minS.top())
		{

		}
	}

	int top()
	{
		return stc.top();
	}

	int getMin()
	{
		return minS.top();
	}

private:
	stack<int> stc;
	stack<int> minS;
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

	std::cout << (que.empty() ? "队列为空" : "队列不为空") << std::endl;

	return 0;
}
