#include "shell.h"
/**
 * readinput - reads input
 *
 * Return: input
 */
char *readinput(void)
{
	char *input = NULL;
	size_t len, n = 0;

	if (getline(&input, &n, stdin) == EOF)
	{
		free(input);
		return (NULL);
	}

	len = strlen(input);

	if (len > 0 && input[len - 1] == '\n')
	{
		input[len - 1] = '\0';
	}
	return (input);
}
