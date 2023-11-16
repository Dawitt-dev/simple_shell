#include "shell.h"
/**
 * main - function
 *
 * Return: always 0
 */
int main(void)
{

	char **args, *input, **env = environ;

	input = NULL;

	while (1)
	{
		printprompt();
		input = readinput();

		if (input == NULL)
		{
			break;
			write(STDOUT_FILENO, "\n", 1);
		}
		args = tokenize(input);
		if (args != NULL && args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exiting(args, input);
				free(args);
				free(input);
			}
			else if (strcmp(args[0], "env") == 0)
			{
				while (*env != NULL)
				{
					write(STDOUT_FILENO, *env, strlen(*env));
					write(STDOUT_FILENO, "\n", 1);
					env++;
				}
				free(args);
			}
			else
			{
				teborne(args);
			}

		}
		free(input);
	}
	return (0);
}

