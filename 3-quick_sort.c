#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - Partitions an array for the quicksort algorithm.
 * @array: Array to be partitioned.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 * @size: Size of the array.
 * Return: Index of the pivot element after partitioning.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = high;
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort_recur - Recursively applies the quicksort algorithm.
 * @array: Array to be sorted.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 * @size: Size of the array.
 */

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

/**
 * quick_sort - Initiates the quicksort algorithm on an array.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recur(array, 0, size - 1, size);
}
