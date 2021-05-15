#include "monty.h"

/**
 *rotr_func - this function rotates the stack to the bottom
 *@head: pointer to stack head
 *@num_lines: number of the line instructions
 */
void rotr_func(stack_t **head, unsigned int num_lines)
{
	stack_t *temp = NULL, *temp2 = NULL, *temp3 = NULL;
	int i = 0;

	(void)num_lines;
	while (temp3 != NULL)
		temp3 = temp3->next, i++;
	if (i < 1)
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
