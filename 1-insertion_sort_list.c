#include "sort.h"

/**
 * swap - Swaps two elements in a doubly linked list.
 * @head: Pointer to the head of the linked list.
 * @x: Pointer to the current element.
 * @y: Pointer to the element to be swapped with current.
 */

void swap(listint_t **head, listint_t **x, listint_t *y)
{
	(*x)->next = y->next;
	if (y->next != NULL)
		y->next->prev = *x;
	y->prev = (*x)->prev;
	y->next = *x;
	if ((*x)->prev != NULL)
		(*x)->prev->next = y;
	else
		*head = y;
	(*x)->prev = y;
	*x = y->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Pointer to the head of the linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *key, *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (key = (*list)->next; key != NULL; key = next)
	{
		next = key->next;
		current = key->prev;
		while (current != NULL && key->n < current->n)
		{
			swap(list, &current, key);
			print_list((const listint_t *)*list);
		}
	}
}
