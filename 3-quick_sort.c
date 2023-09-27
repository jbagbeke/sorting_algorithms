#include "sort.h"

int partition_it(int *array, int low, int high, int size);
void quick_partition(int *array, int low, int high, int size);


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
	int low_temp;

	if (low < high)
	{
		low_temp = partition_it(array, low, high, size);

		partition_it(array, low, low_temp - 1, size);
		partition_it(array, low_temp + 1, high, size);
	}
}


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
	int i;
	int pivot, tmp;

	pivot = array[high];

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			tmp = array[i];
			array[i] = array[low];
			array[low] = tmp;

			print_array(array, size);
			low++;
		}
	}

	tmp = array[low];
	array[low] = pivot;
	array[high] = tmp;

	return (low);
}
