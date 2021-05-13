#include "monty.h"

/**
 *push_func - this function adds node at the beginning stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void push_func(stack_t **head, unsigned int num_lines)
{
	stack_t *new_node, *temp;
	(void)num_lines;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n, new_node->prev = NULL, new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
		temp = *head, new_node->next = *head,
		temp->prev = new_node, *head = new_node;
}

/**
 *pall_func - this function prints the elements of the nodes
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void pall_func(stack_t **head, unsigned int num_lines)
{
	stack_t *h = *head;
	(void)num_lines;
	while (h != NULL)
		printf("%d\n", h->n), h = h->next;
}

/**
 *pint_func - this function prints the value at the top of the stack
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void pint_func(stack_t **head, unsigned int num_lines)
{
	stack_t *h = *head;

	if (h == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", num_lines + 1),
			exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}

/**
 *pop_func - this function premoves the top element of the stack.
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void pop_func(stack_t **head, unsigned int num_lines)
{
	unsigned int len;
	stack_t *head_aux = *head;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", num_lines + 1);
		exit(EXIT_FAILURE);
	}

	len = stack_len(*head);

	if (len == 1)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(head_aux);
	}
}

/**
 * stack_len - function that returns the number of elements in a stack
 * @h: pointer to head stack
 * Return: the number of nodes
 */

size_t stack_len(const stack_t *h)
{
	size_t size = 0;

	while (h)
	{
		h = h->next;
		size++;
	}
	return (size);
}
