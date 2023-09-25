#include "sort.h"

/**
 * insertion_sort_list - Sorts data using insertion algorithm
 * @list: Pointer to a pointer that points to the list to be sorted
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *current = *list, *tmp2, *reversed;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (current->next)
	{
		if (current->n  > current->next->n)
		{
			reversed = current->next;
			while (reversed->prev && reversed->n < reversed->prev->n)
			{
				tmp1 = reversed->next;
				tmp2 = reversed->prev;
				tmp2->next = tmp1;

				if (tmp1)
					tmp1->prev = tmp2;

				reversed->prev = tmp2->prev;
				reversed->next = tmp2;

				if (tmp2->prev)
					tmp2->prev->next = reversed;

				tmp2->prev = reversed;
				if (reversed->prev == NULL)
					*list = reversed;
				print_list(*list);
			}
		}
		else
			current = current->next;
	}
}
