#pragma once
#include<vector>
#include<iostream>
using std::vector;

using namespace std;

namespace my_space {
	void swap(int array[], int i, int j)
	{
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	bool less(int i, int j)
	{
		return i < j;
	}

	bool greater(int i, int j)
	{
		return i > j;
	}
}
void bubblesort(int* array, const int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i && my_space::greater(array[j], array[j + 1]); ++j)
			my_space::swap(array, j, j + 1);
	}
}

void insertsort(int *array, const int size)
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = i; j > 0 && my_space::less(array[j], array[j - 1]); --j)
			my_space::swap(array, j, j - 1);
	}
}

void selectsort(int array[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
			if (my_space::less(array[j], array[min])) min = j;
		my_space::swap(array, i, min);
	}

}

void shellsort(int array[], const int size)
{
	int h = 1;
	while (h < size / 3)
	{
		h = 3 * h + 1;
	}
	while (h >= 1)
	{
		for (int i = h; i < size; ++i)
		{
			for (int j = i; j >= h && my_space::less(array[j], array[j - h]); j -= h)
				my_space::swap(array, j, j - h);
		}
		h = h / 3;
	}
}

void merge(int arr[], int low, int mid, int high);
void mergesort(int arr[], int low, int high) {
	if (low >= high) { return; } 

	int mid = low + (high - low) / 2;  
	mergesort(arr, low, mid);  
	mergesort(arr, mid + 1, high);  
	merge(arr, low, mid, high);  
}

void merge(int arr[], int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;  
	int *temp = new int[high - low + 1];

	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) 
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= high)
		temp[k++] = arr[j++];

	for (i = low, k = 0; i <= high; i++, k++)
		arr[i] = temp[k];
	delete[]temp;
}

int paritition(int arr[], int start, int end)
{
	if (start >= end) return start;
	int l = start, r = end - 1;
	int tmp = arr[l];

	while (l < r)
	{
		while (l < r && tmp <= arr[r])
			--r;
		while (l < r && tmp >= arr[l])
			++l;
		if (l < r)
			my_space::swap(arr, l, r);
	}
	arr[start] = arr[l];
	arr[l] = tmp;
	return l;
}

void quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int pivot = paritition(arr, start, end);
		quickSort(arr, start, pivot);
		quickSort(arr, pivot + 1, end);
	}
}

void heapAdjust(int arr[], int root, int length)
{
	int tmp = arr[root];
	int lchild = 2 * root + 1;
	while (lchild < length)
	{
		if (lchild + 1 < length && arr[lchild] < arr[lchild + 1])
			++lchild;
		if (tmp > arr[lchild])
			break;
		my_space::swap(arr, root, lchild);
		root = lchild;
		lchild = 2 * root + 1;
	}
	arr[root] = tmp;
}

void heapSort(int arr[], int len)
{
	if (arr == nullptr || len <= 0)
		return;
	for (int i = len / 2; i >= 0; --i)
		heapAdjust(arr, i, len);

	for (int i = len - 1; i > 0; --i)
	{
		my_space::swap(arr, 0, i);
		heapAdjust(arr, 0, i);
	}
}