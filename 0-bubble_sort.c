#include "sort.h"

/**
 * swap_v - swaps 2 values in an array of integers
 * @array: the array of integers
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
 * bubble_sort - sorts an array of integers using bubble sort
 * @array: An array of integers
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, nw, i;

	while (n > 1)
	{
		nw = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_values(&array, i - 1, i);
				print_array(array, size);
				nw = i;
			}
		}

		n = nw;
	}
}
