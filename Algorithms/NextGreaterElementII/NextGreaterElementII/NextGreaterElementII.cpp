/*
Given a circular array (the next element of the last element \
is the first element of the array), print the Next Greater Number for \
every element. The Next Greater Number of a number x is the first greater\
number to its traversing-order next in the array,\
which means you could search circularly to find its next greater number.\
If it doesn't exist, output -1 for this number.
*/

#include<stack>
#include<vector>
#include<iostream>

using std::stack;
using std::vector;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, -1);
		stack<int> sc;

		for (int i = 0; i < n * 2; ++i)
		{
			int tmp = i % n;
			while (!sc.empty() && nums[tmp] > nums[sc.top()])
			{
				ans[sc.top()] = nums[tmp];
				sc.pop();
			}

			if (i < n) sc.push(i);	
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> vec = { 1,2,3,1 };

	vector<int> result = s.nextGreaterElements(vec);

	for (int i : result)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
	return 0;
}
