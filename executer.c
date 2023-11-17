#include "shell.h"
/**
 * executecommand - executes
 *@args: argument 1
 *@env: argument 2
 * Return: nothing
 */
void executecommand(char **args, char **env)
{
	char *path;

	path = locate(args[0]);

	if (path != NULL)
	{
		execve(path, args, env);
		perror("Command does not exist\n");
		exit(0);
	}
	else
	{
		perror(args[0]);
		exit(0);
	}
	free(path);

	exit(0);
}
