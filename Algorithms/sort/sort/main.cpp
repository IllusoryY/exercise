#include "helper.h"
#include<cstdlib>
#include<time.h>
#pragma once
#include<iostream>

const int ARRAR_LEN = 10;
using namespace std;
int main()
{
	int* array = new int[ARRAR_LEN];
	for (int i = 0; i < ARRAR_LEN; ++i)
	{
		array[i] = (rand() % 101);
	}

	/*int fd[2];
	for (int i = 0; i < 2; ++i)
	{
		fd[i] = 5;
	}
	for (int i : fd)
		std::cout << i << " ";
	std::cout << std::endl;*/

	cout << "----------ÅÅÐòÇ°----------" << endl;
	int len = ARRAR_LEN;
	for (int i = 0; i < ARRAR_LEN; ++i)
	{
		std::cout << array[i] << " ";
	}
	cout << endl;
	//selectsort(array, len);     //Ñ¡ÔñÅÅÐò
	//insertsort(array, len);
	//bubblesort(array, len);
	//shellsort(array, len);
	//mergesort(array, 0, len - 1);
	//quickSort(array, 0, len);
	heapSort(array, len);
	
	cout << "----------ÅÅÐòºó----------" << endl;
	for (int i = 0; i < len; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	delete[] array;
	system("pause");
	return 0;
}