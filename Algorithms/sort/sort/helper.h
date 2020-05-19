#pragma once
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