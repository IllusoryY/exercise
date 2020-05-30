/*
题目：替换空格
	请实现一个函数，把字符串中的每个空格替换成%20，例如。输入we are happy。则输出we%20are%20happy
*/
#include <iostream>
#include <string>

using namespace std;

void replaceBlank(char str[], int length)
{
	if (str == nullptr && length <= 0)
		return;

	int originalLen = 0;
	int numOfBlank = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++originalLen;

		if (str[i] == ' ') ++numOfBlank;
	}

	int newLen = originalLen + (numOfBlank << 1);
	if (newLen > length) return;

	int indexOfOriginal = originalLen;
	int indexOfNew = newLen;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}



int main()
{
	const int len = 30;
	char ch[len] = "we are happy";
	
	replaceBlank(ch, len);

	for (int i = 0; ch[i] != '\0'; ++i)
		cout << ch[i];

	cout << endl;
	system("pause");
	return 0;
}