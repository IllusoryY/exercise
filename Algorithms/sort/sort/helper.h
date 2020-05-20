#pragma once
#include<vector>
using std::vector;

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

void bubblesort(int* array, const int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i && greater(array[j], array[j + 1]); ++j)
			swap(array, j, j + 1);
	}
}

void insertsort(int *array, const int size)
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = i; j > 0 && less(array[j], array[j - 1]); --j)
			swap(array, j, j - 1);
	}
}

void selectsort(int array[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
			if (less(array[j], array[min])) min = j;
		swap(array, i, min);
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
			for (int j = i; j >= h && less(array[j], array[j - h]); j -= h)
				swap(array, j, j - h);
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