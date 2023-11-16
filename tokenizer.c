#include "shell.h"
/**
 * tokenize - tokenizes input
 *@str: argument
 *@delim: delimiter
 *
 * Return: number of words
 */
size_t tokenizer(char *str, char *delim)
{
	size_t words_count = 0;

	if (strtok(str, delim))
	{
		++words_count;
	}
	while (strtok(NULL, delim))
	{
		++words_count;
	}
	return (words_count);
}
/**
 * word_list(char *str, char *delim)
 *@str: string
 *delim: delimiter
 *
 * Return: array of ptr
 */
char **word_list(char *str, char *delim)
{
	char **arr = NULL;
	size_t i = 0; 
	size_t j = 0, l;
	size_t k = strlen(str);
	char prev_char = '\0';

	if ((j = tokenizer(str, delim)) > 0)
	{
		arr = malloc(sizeof(char *) * (j + 1));

		if (arr == NULL)
		{
			exit(EXIT_FAILURE);
		}

		for (l = 0; l < k; ++l )
		{
			if (str[l] != '\0' && prev_char == '\0')
			{
				arr[i] = str + l;
				++i;
			}
			prev_char = str[l];
		}
		arr[i] = NULL;
	}
	return (arr);
}

