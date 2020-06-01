/*
��Ŀ��쳲���������
	дһ������������n����쳲��������еĵ�n��
*/
#include <iostream>

using namespace std;
long long fib(int n)
{
	int res[] = { 0, 1 };
	if (n < 2)
		return res[n];

	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibOne + fibTwo;
		fibOne = fibTwo;
		fibTwo = fibN;
	}

	return fibN;
}


int main()
{
	cout << fib(1) << endl;
	cout << fib(10) << endl;

	system("pause");
	return 0;
}
