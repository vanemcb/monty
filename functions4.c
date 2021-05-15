#include "monty.h"

/**
 *rotr_func - this function rotates the stack to the bottom
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void rotr_func(stack_t **head, unsigned int num_lines)
{
	stack_t *temp = NULL, *temp2 = NULL;
	int _len = 0;

	(void)num_lines;
	_len = stack_len(*head);
	if (_len > 1)
	{
		temp = *head, temp2 = *head;
		while (temp != NULL)
		{
			if (temp->next == NULL)
			{
				temp->next = temp2, temp2 = temp->prev;
				temp->prev = NULL, temp2->next = NULL;
				(*head)->prev = temp, *head = temp;
				break;
			}
			temp = temp->next;
		}
	}
}
