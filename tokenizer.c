#include "shell.h"
/**
 * tokenize - tokenizes
 *@input: argument
 *
 * Return: args
 */
char **tokenize(char *input)
{
	char *token;
	char **args = malloc((MAX_ARGS + 1) * sizeof(*args));
	int i = 0;

	if (args == NULL)
	{
		perror("malloc");
		exit(0);
	}
	token = strtok(input, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
