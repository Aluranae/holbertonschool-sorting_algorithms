#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order
*                       using the Insertion sort algorithm
*
* @list: Double pointer to the head of the list
*
* Description: Swaps nodes, not values. Prints the list after each swap.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;
	listint_t *next;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;
		prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{
			next = current->next;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			current->prev = prev->prev;

			if (next != NULL)
				next->prev = prev;

			prev->next = next;
			current->next = prev;
			prev->prev = current;

			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}
