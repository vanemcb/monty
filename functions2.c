#include "monty.h"

/**
 *swap_func - this function swaps the top two elements of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void swap_func(stack_t **head, unsigned int num_lines)
{
	int temp = 0, len = 0;
	len = stack_len(*head);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}

/**
 *add_func - this function adds the top two elements of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void add_func(stack_t **head, unsigned int num_lines)
{
	int len = 0;
	stack_t *h = *head;

	len = stack_len(*head);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}

	h->next->n = h->n + h->next->n;
	*head = h->next;
	free(h);
}
