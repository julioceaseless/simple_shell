#include "shell.h"
#include "shell.h"
/**
 * free_dbptr - frees double pointer
 * @ptr: double pointer
 */
void free_dbptr(char **ptr)
{
	int i = 0;

	for (; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}

/**
 * _token - parses string using delimiter and stores it in an array
 * @command: command string to parse
 * @delimiter: separator
 * Return: Array of pointers to strings
 */
char **_token(char *command, char *delimiter)
{
	char **args;
	char *token;
	int i = 0, buffsize = 10;

	if (command == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * buffsize);
	if (!args)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(command, delimiter);
	while (token)
	{
		args[i] = token;
		i++;
		if (i >= buffsize - 1)
		{
			buffsize = buffsize * 2;
			args = realloc(args, sizeof(char *) * buffsize);
			if (args == NULL)
			{
				perror("hsh");
				free_dbptr(args);
				return (NULL);
			}
		}
		token = _strtok(NULL, delimiter);
	}
	args[i] = NULL;

	return (args);
}
