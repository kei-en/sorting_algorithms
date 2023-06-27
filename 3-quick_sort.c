#include "sort.h"

size_t partition(int *array, size_t size);
void print_sort(int *array, size_t size, int start);

/**
 * swap - swaps two values
 * @one: the first value
 * @two: the second value
 */
void swap(int *one, int *two)
{
	int temp;

	temp = *two;
	*two = *one;
	*one = temp;
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 *	quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t p;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	p = partition(array, size);

	quick_sort(array, p);
	quick_sort(array + p, size - p);
}
/**
 * partition - sets the lomutu partition scheme for quick_sort
 * @array: the array to partition
 * @size: the size of the array
 *
 * Return: index of the pivot
 */
size_t partition(int *array, size_t size)
{
	int p;
	size_t i = -1, j;

	if (!array || size < 2)
		return (0);

	p = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= p)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_sort(array, size, 0);
			}
		}
	}

	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}

	return (i + 1);
}

/**
 * print_sort - prints array sorted
 * @array: the array to be printed
 * @size: the size of the array
 * @start: the start of the array
 */
void print_sort(int *array, size_t size, int start)
{
	static int *p = (void *)0;
	static size_t s;

	if (!p && start)
	{
		p = array;
		s = size;
	}

	if (!start)
		print_array(p, s);
}
