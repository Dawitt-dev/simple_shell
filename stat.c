#include "shell.h"
/**
 * create_filepath - creates a filepath
 * @token: token from PATH
 * @args: command arguments
 * Return: new filepath
 */
char *create_filepath(const char *token, const char *args)
{
	size_t token_len = strlen(token);
	size_t filename_len = strlen(args);
	size_t filepath_len;
	char *filepath;

	if (args[0] == '/' || args[0] == '.')
	{
		size_t filepath_len = filename_len + 1;
		char *filepath = malloc(filepath_len);

		if (filepath == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(filepath, args);
		return (filepath);
	}

	filepath_len = token_len + filename_len + 2;
	filepath = malloc(filepath_len);

	if (filepath == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	strcpy(filepath, token);
	filepath[token_len] = '/';
	strcpy(filepath + token_len + 1, args);
	return (filepath);
}

/**
 * loc - locates
 * @path: PATH
 * @args: arguments
 * Return: location
 */
char *loc(char *path, char *args)
{
	char *token, *filepath, *path_cpy;
	struct stat st;

	path_cpy = strdup(path);
	token = strtok(path_cpy, ":");

	while (token != NULL)
	{
		filepath = create_filepath(token, args);

		if (stat(filepath, &st) == 0)
		{
			free(path_cpy);
			return (filepath);
		}

		free(filepath);
		token = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}

