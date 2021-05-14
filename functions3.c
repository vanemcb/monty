#include "monty.h"

/**
 *mul_func - this function multiplies the second top element of
 *the stack with the top element of the stack.
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void mul_func(stack_t **head, unsigned int num_lines)
{
	int len = 0;
	stack_t *h = *head;

	len = stack_len(*head);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}

	h->next->n = h->next->n * h->n;
	*head = h->next;
	free(h);
}

/**
 *mod_func - this function computes the rest of the division of the
 *second top element of the stack by the top element of the stack.
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void mod_func(stack_t **head, unsigned int num_lines)
{
	int len = 0;
	stack_t *h = *head;

	len = stack_len(*head);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}
	if (h->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}
	h->next->n = h->next->n % h->n;
	*head = h->next;
	free(h);
}
