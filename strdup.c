#include "monty.h"

/**
* _strdup - function that returns a pointer to a newly.
* allocated space in memory, which contains a copy of the
* string given as a parameter.
* @str: input string.
* Return: pointer to a newly allocated space in memory.
*/
char *_strdup(char *str)
{
	char *str2 = NULL;
	int i = 0, x;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
		i++;

	str2 = malloc(sizeof(char) * (i + 1));
	if (!str2)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (str2 == NULL)
		return (NULL);

	for (x = 0; x <= i; x++)
		str2[x] = str[x];

	return (str2);
}

/**
 *_strlen - counter of character
 *@s: string
 *Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0, c = 0;

	for ( ; s[i] != '\0' ; i++)
		c++;
	return (c);
}
