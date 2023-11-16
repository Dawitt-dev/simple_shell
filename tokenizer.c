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
	char **args = NULL;
	int i = 0;

	token = strtok(input, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args = append(args, token);
		token = strtok(NULL, " ");
		i++;

	}
	args[i] = NULL;
	return (args);
}
/**
 * append - appends tokens
 *@args: arrgument 1
 *@token: token
 *
 * Return: array
 */
char **append(char **args, char *token)
{
	int j, i = 0;
	char **newArgs;

	while (args != NULL && args[i] != NULL)
	{
		i++;
	}
	newArgs = malloc((i + 2) * sizeof(*newArgs));
	if (newArgs == NULL) 
	{
		perror("malloc");
		exit(0);
	}
	for (j = 0; j < i; j++) 
	{
        	newArgs[j] = args[j];
    	}
	newArgs[i] = malloc(strlen(token) + 1);
	if (newArgs[i] == NULL)
	{
		perror("malloc");
		exit(0);
	}
	strcpy(newArgs[i], token);
	newArgs[i + 1] = NULL;
	free(args);
	return newArgs;
}
