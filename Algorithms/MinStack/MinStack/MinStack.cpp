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

//�����
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

	std::cout << "���е�һ��ֵΪ" << que.peek() << std::endl;
	std::cout << que.pop() << std::endl;

	que.push(3);
	std::cout << "���е�һ��ֵΪ" << que.peek() << std::endl;

	std::cout << (que.empty() ? "����Ϊ��" : "���в�Ϊ��") << std::endl;

	return 0;
}
