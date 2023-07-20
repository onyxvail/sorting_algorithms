#include "sort.h"

/**
 * insertion_sort_list - sorts a dubly linked list of integers
 * @list: the given doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *back, *tmp;

if (!list || !*list || !(*list)->next)
return;
current = (*list)->next;
while (current)
{
back = current;
while (back->prev)
{
tmp = back->prev;
if (back->n < tmp->n)
{
tmp->next = back->next;
back->prev = tmp->prev;
if (back->next)
back->next->prev = tmp;
if (tmp->prev)
tmp->prev->next = back;
else
*list = back;
back->next = tmp;
tmp->prev = back;
print_list(*list);
continue;
}
back = back->prev;
}
current = current->next;
}
}
