#include "main.h"
/**
 * _strtok - function that tokinses a string
 * @str: string to be tokenised
 * @delim: where to tokenise at
 *
 * Return: pointer to next token NULL otherwise
 *
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start = NULL;
	int i;

	if (delim == NULL)
		return (NULL);
	if (str == NULL)
		str = next_token;
	if (str == NULL && next_token == NULL)
		return (NULL);

	token_start = str;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (strchr(delim, str[i]) != NULL)
		{
			str[i] = '\0';
			next_token = str + i + 1;
			return (token_start);
		}
	}

	next_token = NULL;
	if (str == token_start)
		return (token_start);

	return (NULL);
}
