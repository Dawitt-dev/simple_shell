#include "shell.h"
/**
 * exiting - safely exits
 *@input: argument 2
 *@args: arguments 1
 * Return: nothing
 */
void exiting(char **args, char *input)
{

	free(args);
	free(input);
	exit(0);
}
