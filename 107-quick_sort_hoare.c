#include "sort.h"

/**
 * quick_sort_hoare -  sorts an array of integers
 * in ascending order using the Quick sort
 * by implementing Hoare partition scheme
 * @array: array to be sorted
 * @size: length of array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;
	qs_hoare(array, 0, size - 1, size);
}

/**
 * qs_hoare - recursion part of quick sort
 * @array: array to be sorted
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of array
 */
void qs_hoare(int *array, int low, int high, size_t size)
{
	int pindex;

	if (low < high)
	{
		pindex = hoare(array, low, high, size);
		qs_hoare(array, low, pindex, size);
		qs_hoare(array, pindex + 1, high, size);
	}
}

/**
 * hoare - implements the hoare partition
 * @array: array to be sorted and partitioned
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of array
 * Return: index
 */
int hoare(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	i = low;
	j = high;
	pivot = array[high];
	while (i <= j)
	{
		while (array[i] < pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
			i++;
			j--;
		}
	}
	return (j);
}
