#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *	order using the insertion sort algorithm
 * @list: double pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *swap, *prvs;

	if (!list || !*list)
		return;

	curr = *list;
	while ((curr = curr->next))
	{
		swap = curr;
		while (swap->prev && swap->n < swap->prev->n)
		{
			prvs = swap->prev;
			if (swap->next)
				swap->next->prev = prvs;
			if (prvs->prev)
				prvs->prev->next = swap;
			else
				*list = swap;

			prvs->next = swap->next;
			swap->prev = prvs->prev;
			swap->next = prvs;
			prvs->prev = swap;

			print_list(*list);
		}
	}
}
