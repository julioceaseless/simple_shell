#include "shell.h"

/**
 * _token - parses string using delimiter and stores it in an array
 * @command: command string to parse
 * Return: Array of pointers to strings
 */
char **_token(char *command)
{
	char **args;
	char *token;
	int i, buffsize = 1024;

	if (command == NULL)
		return (NULL);
	args = malloc(sizeof(char *) * buffsize);
	if (!args)
	{
		perror("hsh");
		return (NULL);
	}

	token = strtok(command, "\n ");
	for (i = 0; token; i++)
	{
		args[i] = token;
		token = strtok(NULL, "\n ");
	}
	args[i] = NULL;

	return (args);
}
