#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in the ascending order
 * @array: the given int's array
 * @size: the given size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int tmp;

for (i = 0; i < size; i++)
{
for (j = 0; j < (size - 1 - i); j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j + 1];
array[j + 1] = array[j];
array[j] = tmp;
print_array(array, size);
}
}
}
}
