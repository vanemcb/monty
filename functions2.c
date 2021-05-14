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

/**
 *nop_func - this function does nothing
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void nop_func(stack_t **head, unsigned int num_lines)
{
	(void)head;
	(void)num_lines;
}

/**
 *sub_func - this function subtracts the top two elements of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void sub_func(stack_t **head, unsigned int num_lines)
{
	int len = 0;
	stack_t *h = *head;

	len = stack_len(*head);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}

	h->next->n = h->next->n - h->n;
	*head = h->next;
	free(h);
}

/**
 *div_func - this function divides the second top element of the stack
 *by the top element of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void div_func(stack_t **head, unsigned int num_lines)
{
	int len = 0;
	stack_t *h = *head;

	len = stack_len(*head);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}
	if (h->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", num_lines + 1);
		free_stactk(*head), exit(EXIT_FAILURE);
	}
	h->next->n = h->next->n / h->n;
	*head = h->next;
	free(h);
}
