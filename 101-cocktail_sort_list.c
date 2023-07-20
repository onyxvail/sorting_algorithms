#include "sort.h"


/**
 * swap_node - swaps the doubly linked list node
 * @first: first node
 * @second: second node
 *
 * Return: void
 */
void swap_node(listint_t **first, listint_t **second)
{
if ((*first)->prev)
(*first)->prev->next = *second;
if ((*second)->next)
(*second)->next->prev = *first;
(*first)->next = (*second)->next;
(*second)->prev = (*first)->prev;
(*second)->next = *first;
(*first)->prev = *second;
}

/**
 * cocktail_sort_list - sorts the doubly linked list
 * @list: given doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *left, *right;
int swapped;

if (!list || !*list)
return;

left = *list;
do {
swapped = 0;
while (left->next)
{
right = left->next;
if (left->n > right->n)
{
swap_node(&left, &right);
if (!right->prev)
*list = right;
print_list(*list);
swapped = 1;
}
else
left = left->next;
}
right = left->prev;
while (right->prev)
{
left = right->prev;
if (right->n < left->n)
{
if (!left->prev)
*list = right;
swap_node(&left, &right);
print_list(*list);
swapped = 1;
}
else
right = right->prev;
}
} while (swapped);
}
