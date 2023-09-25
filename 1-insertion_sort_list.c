#include <stdio.h>


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !(*list) || !(*list)->next)
        return;

    listint_t *current, *tmp, *prev;

    current = (*list)->next;

    while (current)
    {
        tmp = current;
        prev = current->prev;

        while (prev && tmp->n < prev->n)
        {
            if (tmp->next)
                tmp->next->prev = prev;

            prev->next = tmp->next;
            tmp->prev = prev->prev;

            if (prev->prev)
                prev->prev->next = tmp;
            else
                *list = tmp;

            prev->prev = tmp;
            tmp->next = prev;


            print_list(*list);

            prev = tmp->prev;
        }

        current = current->next;
    }
}

