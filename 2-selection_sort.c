#include "sort.h"

/**
 * swap - swaps two values
 * @one: first value
 * @two: second value
 */
void swap(int *one, int *two)
{
	int temp;

	temp = *two;
	*two = *one;
	*one = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 *	using the selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (i != min)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
