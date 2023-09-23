#include "sort.h"

/**
 * bubble_sort - Sorts ints using the bubble sort algo
 * @array: Array of ints to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= size; j++)
		{
			if ((j + 1) >= size)
				break;

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
