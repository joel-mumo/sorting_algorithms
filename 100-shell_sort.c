#include "sort.h"

/**
 * knuth_max_gap - gets the max gap according the Knuth sequence
 * @size: Size of the array
 * Return: The max gap
 */
size_t knuth_max_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	if (gap >= size)
		gap = (gap - 1) / 3;
	return (gap);
}

/**
 * shell_sort - sorts an array of integers using shell sort - Knuth sequence
 * @array: An array of integers
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size);
{
	size_t gap = 0, i, j;
	int temp;

	gap = knuth_max_gap(size);
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
