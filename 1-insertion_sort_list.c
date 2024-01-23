#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
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
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
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
