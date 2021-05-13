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
