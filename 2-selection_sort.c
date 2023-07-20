#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, current_min;
int tmp;

for (i = 0; i < size; i++)
{
current_min = i;
for (j = i; j < size; j++)
{
if (array[j] < array[current_min])
current_min = j;
}
if (current_min == i)
continue;
tmp = array[current_min];
array[current_min] = array[i];
array[i] = tmp;
print_array(array, size);
}
}
