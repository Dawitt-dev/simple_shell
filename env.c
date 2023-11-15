#include "shell.h"
/**
 * printenv - prints environment
 *
 * Return: Nothing
 */
void printenv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
