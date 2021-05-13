#include "monty.h"

/**
 *call_function - this function calls the instructions of the monty file
 *@head: pointer to stack head
 *@array_line: store the line of file
 *@num_lines: number of the line instructions
 */
void call_function(stack_t **head, char *array_line, int num_lines)
{
	instruction_t instruct[] = {
		{"push", push_func},
		{"pall", pall_func},
		{NULL, NULL},
	};
	int i = 0, _len = 0;
	char **array_lines_token = NULL;

	array_lines_token = _token(array_line, " ");
	if (strcmp(array_lines_token[0], "push") == 0)
	{
		n = atoi(array_lines_token[1]);
		if (n == 0 && array_lines_token[1][0] != '0')
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n"
				, num_lines + 1), free(array_lines_token), exit(EXIT_FAILURE);
	}
	while (instruct[i].opcode != NULL)
	{
		_len = _strlen(instruct[i].opcode);
		if (strncmp(array_lines_token[0], instruct[i].opcode, _len) == 0)
		{
			instruct[i].f(head, num_lines);
			break;
		}
		i++;
	}
	if (instruct[i].opcode == NULL && array_lines_token[0][0] != '\n')
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s", num_lines + 1,
			array_lines_token[0]), free(array_lines_token), exit(EXIT_FAILURE);
	free(array_lines_token);
}
