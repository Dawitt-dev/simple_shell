#include "shell.h"
/**
 * printprompt - prints prompt
 *
 * Returns: nothing
 */
void printprompt(void)
{
	if (isatty(0))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		fflush(stdout);
	}
}
