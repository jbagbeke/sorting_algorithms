#include "sort.h"

/**
 * insertion_sort_list - Sorts data using insertion algorithm
 * @list: Pointer to a pointer that points to the list to be sorted
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *current = *list, *tmp2, *back;

	if (!list || !(*list) || (!(*list)->next))
		return;
	while (current->next != NULL)
	{
		if ((current->n) > (current->next->n))
		{
			tmp1 = current->next;
			tmp2 = current->prev;
			current->prev = tmp1;
			current->next = tmp1->next;
			tmp1->next = current;
			tmp1->prev = tmp2;
			tmp2->next = tmp1;
			back = tmp1;
			print_list(*list);

			while (back->prev != NULL && back->n < back->prev->n)
			{
				tmp1 = back->next;
				tmp2 = back->prev;
				tmp2->next = tmp1;
				tmp1->prev = tmp2;
				back->prev = tmp2->prev;
				back->next = tmp2;
				if (tmp2->prev != NULL)
					tmp2->prev->next = back;
				tmp2->prev = back;
				if (back->prev == NULL)
					*list = back;
				print_list(*list);
			}
		}
		else
			current = current->next;
	}
}
