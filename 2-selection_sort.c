#include "sort.h"

/**
* selection_sort - Sorts an array of integers in ascending order
*                  using the Selection sort algorithm
*
* @array: The array to be sorted
* @size: The number of elements in the array
*
* Description: Prints the array after each swap of two elements.
*/

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[min_idx];
			array[min_idx] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
