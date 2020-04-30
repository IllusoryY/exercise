/*
Given a list of daily temperatures T, return a list such that,\
for each day in the input, tells you how many days you would have to\
wait until a warmer temperature. If there is no future day \
for which this is possible, put 0 instead.

For example, given the list of temperatures \
T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be\
[1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000].\
Each temperature will be an integer in the range [30, 100].
*/

#include<stack>
#include<vector>
#include<iostream>

using std::stack;
using std::vector;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> ans(n, 0);
		stack<int> sc;

		for (int i = 0; i < n; ++i)
		{
			while (!sc.empty() && T[i] >= T[sc.top()])
			{
				int tmp = sc.top();
				ans[tmp] = i - tmp;
				sc.pop();
			}
			sc.push(i);
		}

		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> vec = { 73, 74, 75, 71, 69, 72, 76, 73 };
	
	vector<int> result = s.dailyTemperatures(vec);

	for (int i : result)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}
