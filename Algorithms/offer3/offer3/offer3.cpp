/*
题目1：找出数组中重复的数字
	在一个长度为n的数组里的所有数字都在0至n-1范围内，数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了\
	几次。请找出数组中任意一个重复的数字。

题目2：不修改数组找出重复的数字
	在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能\
	修改输入的数组
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//自己解法
vector<int> solution(int arr[], int len)
{
	vector<int> rvec;
	set<int> m;

	for (int i = 0; i < len; ++i)
	{
		if(m.find(arr[i]) == m.end())
			m.insert(arr[i]);
		else
			rvec.push_back(arr[i]);
	}
	
	return rvec;
}

//利用哈希表解法（题目一）
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;

	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			int tmp = numbers[i];
			numbers[i] = numbers[tmp];
			numbers[tmp] = tmp;
		}
	}
	return false;
}

//二分查找思路(题目二)
int getDuplication(const int* numbers, int length)
{
	if (!numbers || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int mid = ((end - start) >> 1) + start;
		int cnt = countRange(numbers, length, start, mid);
		if (end == start)
		{
			if (cnt > 1)
				return start;
			else
				break;
		}

		if (cnt > (mid - start + 1))
			end = mid;
		else
			start = mid + 1;
	}
	return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
	if (!numbers) return 0;

	int cnt = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++cnt;
	}
	return cnt;
}

int main()
{
	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };
	int arrLen = sizeof(arr) / sizeof(int);

	vector<int> ivec = solution(arr, arrLen);
	for (int v : ivec)
		cout << v << " ";
	cout << endl;

	system("pause");
	return 0;
}