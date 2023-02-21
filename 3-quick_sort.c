#include "sort.h"

/**
 * swap_v - swaps two values in an array of integers
 * @array: an array of integers
 * @index1: index of first value
 * @index2: index of second value
 * Return: An array of values
 */
void swap_v(int **array, ssize_t index1, ssize_t index2)
{
	int temp;

	temp = (*array)[index1];

	(*array)[index1] = (*array)[index2];
	(*array)[index2] = temp;
}

/**
 * pivot - sets a pivot point in the array
 * @array: the array to sort
 * @min: the lowest index of the pivot to sort
 * @max: the highest index of the pivot to sort
 * @size: size of the array
 * Return: Index of the pivot
 */
size_t pivot(int *array, ssize_t min, ssize_t max, size_t size)
{
	int p;
	ssize_t i, j;

	p = array[max];
	i = min;
	for (j = min; j < max; j++)
	{
		if (array[j] < p)
		{
			if (i != j)
			{
				swap_v(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[max] < array[i])
	{
		swap_v(&array, i, max);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_p - partitions an  array, then sorts each partition
 * @array: the array to sort
 * @min: the lowest index of the pivot to sort
 * @max: the highest index of the pivot to sort
 * @size: size of the array
 */
void quick_sort_p(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t p;

	if (min < max)
	{
		p = pivot(array, min, max, size);
		quick_sort_p(array, min, p - 1, size);
		quick_sort_p(array, p + 1, max, size);
	}
}

/**
 * quick_sort - sorts an array of integers using quicksort
 * @array: An array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t min = 0;
	ssize_t max = (size - 1);

	if (!array || size < 2)
		return;

	quick_sort_p(array, min, max, size);
}
