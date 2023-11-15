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
			printf("\n");
		}
		args = tokenize(input);
		if (args != NULL && args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exiting(args, input);
			}
			else if (strcmp(args[0], "env") == 0)
			{
				while (*env != NULL)
				{
					printf("%s\n", *env);
					env++;
				}
			}
			else
			{
				teborne(args);
			}
			free(args);
		}
		free(input);
	}
	return (0);
}

