#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: The function sorts the elements of the array in
 * ascending order using the Selection Sort algorithm. It divides
 * the array into a sorted and an unsorted region. In each iteration,
 * it finds the minimum element from the unsorted region and swaps
 * it with the first element of the unsorted region, expanding the
 * sorted region.
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j, min, tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}

		}
		if (i != min)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
