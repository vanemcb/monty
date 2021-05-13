#include "monty.h"

/**
 * free_stactk - function that free the node of a list
 * @head: pointer when start the list
 */
void free_stactk(stack_t *head)
{
	stack_t *aux;

	while (head != NULL)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
