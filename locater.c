#include "shell.h"
/**
 * locate - locates
 *@args: arguments
 * Return: location
 */
char *locate(char *args)
{
	char *path;

	path = getenv("PATH");

	if (path)
	{
		path = loc(path, args);
		return (path);
	}
	return (NULL);
}
