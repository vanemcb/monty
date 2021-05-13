#include "monty.h"

int cont_lines(char *buff, char delim)
{
	int i = 0, num_words = 0;

	for (; buff[i] != '\0'; i++)
	{
		if (delim == buff[i])
			num_words++;
	}
	return (num_words + 1);
}
