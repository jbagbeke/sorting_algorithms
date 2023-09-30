#include "sort.h"

/**
 * knuth_seq - Generates number <= to size using the knuth seq
 * @num: Pointer to the number <= size
 * @size: Size of the array
 * Return: Void
 */
void knuth_seq(int *num, size_t size)
{
	int intval = 1;

	while ((size_t)intval <= size)
	{
		*num = intval;
		intval = intval * 3 + 1;
	}
}

/**
 * knuth_shell - Performs insertion sort on array
 * @array: Array to perform sort on
 * @size: Size of the array
 * @intval: Interval from knuth sequence
 * Return: Void
 */
void knuth_shell(int *array, size_t size, int intval)
{
	size_t i;
	int tmp;

	for (i = 0; i < size; i++)
	{
		if (i + intval <= size - 1)
		{
			if (array[i] > array[i + intval])
			{
				tmp = array[i];
				array[i] = array[i + intval];
				array[i + intval] = tmp;
			}
		}
	}
}

/**
 * shell_sort - Sorts an array using the shell sort algo
 * @array: the array to sort
 * @size: Size of the array
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t i;
	int intval;

	if (!array || size == 1 || size == 0)
		return;

	knuth_seq(&intval, size);

	while (intval >= 1)
	{
		for (i = 0; i < size; i++)
			knuth_shell(array, size, intval);

		intval = (intval - 1) / 3;
		print_array(array, size);
	}
}
