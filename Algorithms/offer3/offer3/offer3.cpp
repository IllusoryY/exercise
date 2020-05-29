/*
��Ŀ1���ҳ��������ظ�������
	��һ������Ϊn����������������ֶ���0��n-1��Χ�ڣ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ���\
	���Ρ����ҳ�����������һ���ظ������֡�

��Ŀ2�����޸������ҳ��ظ�������
	��һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�����������������һ���������ظ��ġ����ҳ�����������һ���ظ������֣�������\
	�޸����������
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//�Լ��ⷨ
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

//���ù�ϣ��ⷨ����Ŀһ��
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

//���ֲ���˼·(��Ŀ��)
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