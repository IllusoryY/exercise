/*
题目：用两个栈实现队列
	用两个栈实现队列，队列的声明如下，请实现它的两个函数appendTail和deleteHead.
分别完成在队里尾部插入节点和在队列头部删除节点的功能
*/
#include <stack>
using std::stack;

template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> s1;
	stack<T> s2;
};

template<typename T>
void CQueue<T>::appendTail(const T& node)
{
	s1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	while(!s1.empty() && s2.empty())
	{
		T tmp = s1.top();
		s1.pop();
		s2.push(tmp);
	}

	if (s2.size() == 0)
		throw new exception("queue is empty");

	T ret = s2.top();
	s2.pop();
	return ret;
}