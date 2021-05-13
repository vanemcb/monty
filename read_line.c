#include "monty.h"

/**
 *read_line - this function read the lines of the monty file
 *@file_name: the file
 *@num_lines: number of the line instructions
 *Return: array with each line of the file
 */
char **read_line(char *file_name, int num_lines)
{
	char *line_buf = NULL, **array_lines = NULL;
	size_t size = 0;
	int i = 0;
	ssize_t line_size = 0;
	FILE *fd = fopen(file_name, "r");

	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	array_lines = malloc(sizeof(char *) * (num_lines + 1));
	if (!array_lines)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	line_size = getline(&line_buf, &size, fd);
	while (line_size >= 0)
	{
		array_lines[i] = line_buf;
		line_buf = NULL;
		line_size = getline(&line_buf, &size, fd);
		i++;
	}
	array_lines[i] = NULL;

	free(line_buf);
	fclose(fd);
	return (array_lines);
}
