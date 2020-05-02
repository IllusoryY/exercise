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

using std::stack;

class MinStack
{
public:
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
			minS.pop();
		}
		stc.pop();
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
	MinStack sc;
	sc.push(2);
	sc.push(1);

	std::cout << "最小值为" << sc.getMin() << std::endl;
	sc.pop();

	sc.push(3);
	std::cout << "最小值为" << sc.getMin() << std::endl;

	return 0;
}
