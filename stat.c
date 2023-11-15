#include "shell.h"
/**
 * loc - Locate a command in the PATH
 *@path: The name of the command to locate
 *@args: arguments
 * Return: Path
 */
char *loc(char *path, char *args)
{
	char *token, *filepath, *path_cpy;
	size_t filepath_len, token_len, filename_len;
	struct stat st;

	path_cpy = strdup(path);
	token = strtok(path_cpy, ":");

	while (token != NULL)
	{
		token_len = strlen(token);
		filename_len = strlen(args);
		if (args[0] == '/' || args[0] == '.')
		{
			filepath_len = filename_len + 1;
			filepath = malloc(filepath_len);

			if (filepath == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(filepath, args);
		}
		else
		{
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
		}
		if (stat(filepath, &st) == 0)
		{
			free(path_cpy);
			return(filepath);
		}
		free(filepath);
		token = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}
