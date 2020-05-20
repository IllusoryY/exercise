#include<iostream>
#include "helper.h"

int main()
{
	int array[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	int len = sizeof(array) / sizeof(array[0]);
	//selectsort(array, len);     //—°‘Ò≈≈–Ú
	//insertsort(array, len);
	//bubblesort(array, len);
	//shellsort(array, len);

	mergesort(array, 0, len - 1);
	for (int i = 0; i < len; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}