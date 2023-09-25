#include "sort.h"

/**
 * lomuto_partition - Partition the array using Lomuto partition.
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 */
void quicksort(int *array, int size, int low, int high)
{

	if (low < high)
	{
		int pivot_index = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, pivot_index - 1);
		quicksort(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
