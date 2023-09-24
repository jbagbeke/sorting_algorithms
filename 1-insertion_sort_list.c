#include "sort.h"

/**
 * insertion_sort_list - Sorts data using insertion algorithm
 * @list: Pointer to a pointer that points to the list to be sorted
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2, *head, *fls_head;
	listint_t *p_node, *n_node;

	head = *list;
	p_node = head->prev;
	while (head)
	{
		n_node = head->next;

		if (head->n > n_node->n)
		{
			head->prev = p_node->prev;
			head->next = p_node;
			p_node->prev = head;
			p_node->next = n_node;
			tmp1 = head;
			head = p_node;
			p_node = tmp1;
			print_list((const listint_t *)*list);
			
			fls_head = p_node;

			if (fls_head->n < fls_head->prev->n)
			{
				while (fls_head != NULL && fls_head->prev != NULL)
				{
					tmp1 = fls_head->prev;
					tmp1->next = fls_head->next;
					tmp1->prev = fls_head;
					tmp2 = tmp1->prev;
					fls_head->prev = tmp2;
					fls_head->next = tmp1;
					tmp2->next = fls_head;
					print_list((const listint_t *)*list);
				}
			}
		}
		p_node = head;
		head = head->next;
	}
}





listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
