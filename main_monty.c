#include "monty.h"

/**
 *main - program that execute a monty file
 *@ac: number of input arguments
 *@av: array that have the file name
 *Return: 0 or 1 if the program fails
 */
int main(int ac, char **av)
{
	char **array_lines = NULL;
	int num_lines = 0;
	stack_t *head = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	array_lines = read_m(av[1]);
	while (array_lines[num_lines])
	{
		call_function(&head, array_lines[num_lines], num_lines);
		free(array_lines[num_lines]);
		num_lines++;
	}
	free(array_lines);
	free_stactk(head);
	return (0);
}
