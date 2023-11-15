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
		printf("%s\n", *env);
		env++;
	}
}
