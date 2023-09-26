#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort algo
 * @array: Array to sort
 * @size: Size of the array
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t tmp, i, j, mini, index;

	if (size == 0 || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		j = i + 1;
		mini = array[i];

		while (j < size)
		{
			if (array[j] < mini)
			{
				mini = array[j];
				index = j;
			}

			++j;
		}

		if (array[i] != mini)
		{
			tmp = array[i];
			array[i] = mini;
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
