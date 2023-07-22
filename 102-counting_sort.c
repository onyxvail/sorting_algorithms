#include "sort.h"

/**
 * counting_sort - counting sort function
 * @array: array to be sorted
 * @size: array size
 *
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
size_t i = 0, j = 0;
int max = 1, min = array[0];
int *cpy, *count;

if (!array || !*array || size <= 1)
return;
cpy = malloc(sizeof(int) * size);
for (i = 0; i < size; i++)
{
if (array[i] > min)
min = array[i];
}
count = malloc(sizeof(int) * (min + 1));
for (i = 0; i < size; i++)
count[array[i]]++;
while (max < min)
{
count[max + 1] += count[max];
max++;
}
print_array(count, max + 1);
for (i = 0; i < size; i++)
{
count[array[i]]--;
cpy[count[array[i]]] = array[i];
}
while (j < size)
{
array[j] = cpy[j];
j++;
}
free(cpy);
free(count);
}
