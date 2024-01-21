#include "sort.h"

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}


int partition(int *array, int low, int high, size_t size)
{	
	int pivot, i, j;

	pivot = high;
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= array[pivot])
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	print_array(array, size);
	return (i);
}

void quicksort_recur(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high, size);
		quicksort_recur(array, low, pivot_idx - 1, size);
		quicksort_recur(array, pivot_idx + 1, high, size);
	}
}
void quick_sort(int *array, size_t size)
{
	quicksort_recur(array, 0, size - 1, size);
}
