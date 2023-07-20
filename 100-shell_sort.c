#include "sort.h"

/**
 * shell_sort - sorts an array of ints
 * @array:  given array
 * @size:  given size
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1;
size_t i, j;
int insertion;

if (!array || !size)
return;
while (gap < size / 3)
gap = gap * 3 + 1;
while (gap > 0)
{
for (i = gap; i < size; i++)
{
insertion = array[i];
j = i;
while (j > (gap - 1) && array[j - gap] >= insertion)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = insertion;
}
gap /= 3;
print_array(array, size);
}
}
