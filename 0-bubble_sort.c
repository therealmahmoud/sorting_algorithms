#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: The function sorts the elements of the array in
 * ascending order using the Bubble Sort algorithm. It repeatedly
 * steps through the list, compares adjacent elements, and swaps
 * them if they are in the wrong order. The process is repeated
 * until the array is sorted.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
