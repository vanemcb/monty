#include "monty.h"

/**
 *read_m - this function read the monty file
 *@file_name: the file
 *Return: array with each line of the file
 */
char **read_m(char *file_name)
{
	char *buffer = NULL, **array_lines = NULL;
	int fd = 0, bytes_read = 0, num_lines;

	buffer = malloc(1024);
	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_name);
		free(buffer);
		exit(EXIT_FAILURE);
	}

	bytes_read = read(fd, buffer, 1024);
	buffer[bytes_read] = '\0';

	num_lines = cont_lines(buffer, '\n');
	array_lines = read_line(file_name, num_lines);

	close(fd);
	free(buffer);
	return (array_lines);
}

