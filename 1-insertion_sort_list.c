#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 * @list: A pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *num1, *num2;

	if (list == NULL || *list == NULL)
		return;

	num1 = (*list)->next;

	while (num1 != NULL)
	{
		num2 = num1->next;
		while (num1->prev != NULL && num1->prev->n > num1->n)
		{
			num1->prev->next = num1->next;

			if (num1->next)
				num1->next->prev = num1->prev;

			num1->next = num1->prev;
			num1->prev = num1->next->prev;
			num1->next->prev = num1;

			if (!num1->prev)
				*list = num1;
			else
				num1->prev->next = num1;
			print_list(*list);
		}
		num1 = num2;
	}
}
