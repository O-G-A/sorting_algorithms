#include "sort.h"

/**
 * swap_backward - that sorts a doubly linked list of integers
 * @list: doubly Pointers
 * @tail_n: pointers finally doubly linked
 * @runner_n: Doubly Pointers the value
 */

void swap_backward(listint_t **list, listint_t **tail_n, listint_t **runner_n)
{
	listint_t *tmp = (*runner_n)->prev;

	if ((*runner_n)->next)
		(*runner_n)->next->prev = tmp;
	else
		*tail_n = tmp;
	tmp->next = (*runner_n)->next;
	(*runner_n)->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = *runner_n;
	else
		*list = *runner_n;
	(*runner_n)->next = tmp;
	tmp->prev = *runner_n;
	*runner_n = tmp;
	print_list(*list);
}

/**
 * swap_forward - that sorts a doubly linked list of integers
 * @list: doubly Pointers
 * @tail_n: pointers finally doubly linked
 * @runner_n: Doubly Pointers the value
 */
void swap_forward(listint_t **list, listint_t **tail_n, listint_t **runner_n)
{
	listint_t *tmp = (*runner_n)->next;

	if ((*runner_n)->prev)
		(*runner_n)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*runner_n)->prev;
	(*runner_n)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *runner_n;
	else
		*tail_n = *runner_n;
	(*runner_n)->prev = tmp;
	tmp->next = *runner_n;
	*runner_n = tmp;
	print_list(*list);
}
/**
 * cocktail_sort_list - print doubly a doubly linked list
 * @list: doubly Pointers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *runner, *tail;
	int band = 1;

	if (!list || !*list || !(*list)->next)
		return;

	for (tail = *list; tail->next; )
		tail = tail->next;
	while (band == 1)
	{
		band = 2;
		for (runner = *list; runner != tail; runner = runner->next)
		{
			if (runner->n > runner->next->n)
			{
				swap_forward(list, &tail, &runner);
				band = 1;
			}

		}
		for (runner = runner->prev; runner != *list; runner = runner->prev)
		{
			if (runner->n < runner->prev->n)
			{
				swap_backward(list, &tail, &runner);
				band = 1;
			}
		}
	}
}
