#include "sort.h"
/**
 * swap - swapping two ints
 * @first: first int
 * @second: second int
 *
 * Return: void
 */
void swap(int *first, int *second)
{
int tmp;

tmp = *first;
*first = *second;
*second = tmp;
}

/**
 * partition - partitionate an array that is seperated by pivot
 * @array: given array
 * @low: lowest value of the array
 * @high: highest value of the array
 * @size: size of the array
 *
 * Return: the pivot position as int
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = high;
int i = low - 1, j;

for (j = low; j <= high; j++)
{
if (array[j] <= array[pivot])
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
return (i);
}

/**
 * quick_sort_lumoto - sorts recursively an array of int
 * @array:given array of int
 * @low: lowest value of the array
 * @high: highest value of the array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_lumoto(int *array, int low, int high, size_t size)
{
int prt;

if (low < high)
{
prt = partition(array, low, high, size);
quick_sort_lumoto(array, low, prt - 1, size);
quick_sort_lumoto(array, prt + 1, high, size);
}
}

/**
 * quick_sort - sorts an array of ints
 * @array: given array of integers
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
if (!array || !size)
return;
quick_sort_lumoto(array, 0, size - 1, size);
}
