#include "sort.h"

/**
 * swap_v - swaps two values in an array of integers
 * @array: An array of integers
 * @index1: index of first value
 * @index2: index of the secong value
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
 * selection_sort - sorts an array of integers using selection sort
 * @array: An array of integers
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m;

	for (i = 0; i < size - 1; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m])
				m = j;
		}

		if (m != i)
		{
			swap_v(&array, m, i);
			print_array(array, size);
		}
	}
}
