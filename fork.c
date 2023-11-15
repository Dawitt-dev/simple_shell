#include "shell.h"
/**
 * teborne - creats and executes child
 *@args: arguments
 * Return: Nothing
 */
void teborne(char **args)
{
	pid_t pid;
	int status;
	char **env = environ;


	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	else if (pid == 0)
	{
		executecommand(args, env);
	}
	else
	{
		wait(&status);
	}
}
