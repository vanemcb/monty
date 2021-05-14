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
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{NULL, NULL},
	};
	int i = 0;
	char **array_lines_token = NULL;

	array_lines_token = _token(array_line, " ");
	array_lines_token[0] = delete_jump(array_lines_token[0]);
	error_push(head, array_lines, array_line, array_lines_token, num_lines);
	while (instruct[i].opcode != NULL)
	{
		if (strcmp(array_lines_token[0], instruct[i].opcode) == 0)
		{
			instruct[i].f(head, num_lines);
			break;
		}
		i++;
	}
	if (instruct[i].opcode == NULL && array_lines_token[0][0] != '\n' &&
		array_lines_token[0][0] != '#')
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

/**
 *error_push - this function checks error push
 *@head: pointer to stack head
 *@array_lines_token: input line
 *@array_lines: double pointer to free
 *@array_line: store the line of file
 *@array_lines_token: input line
 *@num_lines: number of the line instructions
 */
void error_push(stack_t **head, char **array_lines, char *array_line,
	char **array_lines_token, int num_lines)
{
	int x = 0, i = 0;
	char i2;

	while (array_lines_token[x])
		x++;
	if (strcmp(array_lines_token[0], "push") == 0)
	{
		if (x > 1)
			n = atoi(array_lines_token[1]);
		if (x == 1 || (n == 0 && array_lines_token[1][0] != '0'))
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", num_lines + 1),
			free(array_line), free(array_lines), free_stactk(*head),
			free(array_lines_token), exit(EXIT_FAILURE);
	}
}
