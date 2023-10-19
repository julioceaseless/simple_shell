#include "shell.h"
/**
 * _strtok - function that tokinses a string
 * @str: string to be tokenised
 * @delim: where to tokenise at
 *
 * Return: pointer to next token NULL otherwise
 */
#include <stdio.h>
#include <string.h>

char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start = NULL;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL)
		return (NULL);

	while (*next_token != '\0' && strchr(delim, *next_token) != NULL)
	{
		next_token++;
	}

	if (*next_token == '\0')
		return (NULL);

	token_start = next_token;
	while (*next_token != '\0' && strchr(delim, *next_token) == NULL)
	{
		next_token++;
	}

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return (token_start);
}
