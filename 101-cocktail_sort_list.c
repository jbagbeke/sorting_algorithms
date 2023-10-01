#include "sort.h"

/**
 * cock_tail - Does insertion sort algo but in reverse direction
 * @list: Pointer to the Last Node in list
 * @real_list: Pointer to first node(Original Pointer)
 * @num: Variable to signal termination
 * Return: Void
 */
void cock_tail(listint_t *list, listint_t **real_list, int *num)
{
	listint_t *backwd, *tmp1, *tmp2;

	*num = 0;
	while (list->prev)
	{
		backwd = list->prev;

		if (list->n < backwd->n)
		{
			tmp1 = backwd->prev;
			tmp2 = list->next;

			if (tmp2)
				tmp2->prev = backwd;

			backwd->next = list->next;
			backwd->prev = list;

			list->next = backwd;
			list->prev = tmp1;

			if (tmp1)
				tmp1->next = list;

			if (!list->prev)
				*real_list = list;

			print_list(*real_list);
			(*num)++;
		}
		else
			list = list->prev;
	}
}


/**
 * cocktail_sort_list - Sorts a d-linked using the Cocktail shaker sort algo
 * @list: List to sort
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *forwd, *tmp1, *tmp2;
	int terminate;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	while (current->next)
	{
		forwd = current->next;
		if (current->n > forwd->n)
		{
			tmp1 = forwd->next;
			tmp2 = current->prev;

			if (tmp1)
				tmp1->prev = current;
			current->next = tmp1;
			current->prev = forwd;
			forwd->next = current;
			forwd->prev = tmp2;
			if (!forwd->prev)
				 *list = forwd;
			if (tmp2)
			{
				tmp2->next = forwd;
				if (!tmp2->prev || !forwd->prev)
					*list = tmp2;
			}
			print_list(*list);
		}
		else
			current = current->next;
		if (!current->next)
		{
			cock_tail(current, list, &terminate);
			if (terminate != 0)
				current = *list;
		}
	}
}
