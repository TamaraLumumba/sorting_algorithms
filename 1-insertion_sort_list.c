#include "sort.h"

/**
 * swap_n - a funstion that changes two node positions
 * @node: variable structure
 * @list: variable structure
 */

void swap_n(listint_t **node, listint_t **list)
{
	listint_t *head = *node;
	listint_t *temp1, *temp2;

	if (!(*node)->prev)
		*list = (*node)->next;

	temp1 = head->next;
	head->next = temp1->next;
	temp2 = head->prev;
	head->prev = temp1;
	temp1->next = head;
	temp1->prev = temp2;

	if (temp1->prev)
		temp1->prev->next = temp1;
	if (head->next)
		head->next->prev = head;

	*node = temp1;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (!list || !*list)
		return;

	node = *list;

	while (node && node->next)
	{
		if (node->n > node->next->n)
		{
			swap_n(&node, list);
			print_list(*list);

			while (node && node->prev)
			{
				if (node->n < (node->prev)->n)
				{
					node = node->prev;
					swap_n(&node, list);
					print_list(*list);
					node = node->next;
				}
				node = node->prev;
			}
		}
		node = node->next;
	}
}
