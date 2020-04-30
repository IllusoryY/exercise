/*
Given a string containing just the characters\
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/
#include<stack>
#include<iostream>

using std::stack;
using std::string;

class Solution {
public:
	bool isValid(string s) 
	{
		for (char& c : s)
		{
			switch (c)
			{
			case('{'):
			case('['):
			case('('):
				sc.push(c);
				break;
			case(']'):
			{
				if (sc.top() != '[' || sc.empty()) return false;
				sc.pop();
				break;
			}
			case('}'):
			{
				if (sc.top() != '{' || sc.empty()) return false;
				sc.pop();
				break;
			}
			case(')'):
			{
				if (sc.top() != '(' || sc.empty()) return false;
				sc.pop();
				break;
			}
			default:
				break;
			}
		}
		return sc.empty();
	}

private:
	stack<char> sc;
};


int main()
{
	Solution s;
	string s1 = "[({})]";
	string s2 = "{{{";

	std::cout << (s.isValid(s1) ? "·ûºÅÆ¥Åä" : "·ûºÅ²»Æ¥Åä") << std::endl;
	std::cout << (s.isValid(s2) ? "·ûºÅÆ¥Åä" : "·ûºÅ²»Æ¥Åä") << std::endl;

	system("pause");
	return 0;
}
