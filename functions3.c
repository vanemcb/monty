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
		exit(EXIT_FAILURE);
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

/**
 *pchar_func - this function prints the char at the top of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void pchar_func(stack_t **head, unsigned int num_lines)
{
	if (*head == NULL)
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", num_lines + 1),
		free_stactk(*head), exit(EXIT_FAILURE);
	if ((*head)->n >= 32 && (*head)->n <= 126)
		putchar((*head)->n), putchar('\n');
	else
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
		num_lines + 1), free_stactk(*head), exit(EXIT_FAILURE);
}

/**
 *pstr_func - this function prints the string starting at the top of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void pstr_func(stack_t **head, unsigned int num_lines)
{
	stack_t *temp = NULL;

	(void)num_lines;
	temp = *head;
	if (*head != NULL)
	{
		while (temp != NULL)
		{
			if (temp->n >= 32 && temp->n <= 126)
				putchar(temp->n);
			else
				break;
			temp = temp->next;
		}
		putchar('\n');
	}
	else
		putchar('\n');
}
