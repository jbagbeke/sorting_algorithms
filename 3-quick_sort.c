#include "sort.h"

/**
 * partition_it - Partitions array using Lomuto part scheme
 * @array: Array to partition
 * @low: Partition index
 * @high: Size of the array to be partitioned
 * @size: Original size of the array
 * Return: Index of sorted element
 */
int partition_it(int *array, int low, int high, int size)
{
	int tmp, i, pivot;

	pivot = array[high];

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (low < i)
			{
				tmp = array[i];
				array[i] = array[low];
				array[low] = tmp;

				print_array(array, size);
			}
			low++;
		}
	}

	if (pivot < array[low])
	{
		tmp = array[low];
		array[low] = pivot;
		array[high] = tmp;
		print_array(array, size);
	}

	return (low);
}


/**
 * quick_partition - Partitions array using Lomuto part scheme
 * @array: Array to partition
 * @low: Partition index
 * @high: Size of the array to be partitioned
 * @size: Original size of the array
 * Return: Void
 */
void quick_partition(int *array, int low, int high, int size)
{
	int ppos;

	if (low < high)
	{
	ppos = partition_it(array, low, high, size);

	quick_partition(array, low, ppos - 1, size);
	quick_partition(array, ppos + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array using quick sort algo
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	quick_partition(array, 0, size - 1, size);
}
