#include "monty.h"

/**
 *call_function - this function calls the instructions of the monty file
 *@head: pointer to stack head
 *@array_lines: double pointer to free
 *@array_line: store the line of file
 *@num_lines: number of the line instructions
 */
void call_function(stack_t **head, char **array_lines,
				   char *array_line, int num_lines)
{
	instruction_t instruct[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{NULL, NULL},
	};
	int i = 0, x = 0;
	char **array_lines_token = NULL;

	array_lines_token = _token(array_line, " ");
	while (array_lines_token[x])
		x++;
	array_lines_token[0] = delete_jump(array_lines_token[0]);
	if (strcmp(array_lines_token[0], "push") == 0)
	{
		if (x > 1)
			n = atoi(array_lines_token[1]);
		if (x == 1 || (n == 0 && array_lines_token[1][0] != '0'))
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", num_lines + 1),
			free(array_line), free(array_lines),
			free_stactk(*head), free(array_lines_token), exit(EXIT_FAILURE);
	}
	while (instruct[i].opcode != NULL)
	{
		if (strcmp(array_lines_token[0], instruct[i].opcode) == 0)
		{
			instruct[i].f(head, num_lines);
			break;
		}
		i++;
	}
	if (instruct[i].opcode == NULL && array_lines_token[0][0] != '\n')
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", num_lines + 1,
				array_lines_token[0]),
			free(array_line), free(array_lines),
			free_stactk(*head), free(array_lines_token), exit(EXIT_FAILURE);
	free(array_lines_token);
}

/**
 *delete_jump - this function replace the character '\n' by the character '\0'
 *@array_lines_token: input line
 *Return: array lines token modified
 */
char *delete_jump(char *array_lines_token)
{
	int _l = 0;

	_l = _strlen(array_lines_token);
	if (_l != 1)
	{
		if (array_lines_token[_l - 1] == '\n')
			array_lines_token[_l - 1] = '\0';
	}
	return (array_lines_token);
}
