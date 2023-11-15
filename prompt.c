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
		printf("#cisfun$ ");
		fflush(stdout);
	}
}
