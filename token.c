#include "shell.h"
/**
 * token - splits a string of commands into entries
 * @command: string of command + arguments
 * @delimeter: separater
 * Return: an array of strings
 */
char **token(char *command, char *delimeter)
{
	char **args = NULL, *token = NULL, *buffer = NULL, *command_ = NULL;
	int i = 0;

	if (command == NULL || delimeter == NULL)
		return (NULL);
	command_ = strdup(command);
	if (command_ == NULL)
		return (NULL);

	token = strtok(command_, delimeter);
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		buffer =  malloc(strlen(token) + 1);
		if (buffer == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		strcpy(buffer, token);
		args = realloc(args, (sizeof(char *)) * (i + 1));
		if (args == NULL)
		{
			perror("realloc");
			return (NULL);
		}
		args[i] = buffer;
		i++;
		token = strtok(NULL, delimeter);
	}
	args = realloc(args, sizeof(char *) * (i + 1));
	if (args == NULL)
	{
		perror("realloc");
		return (NULL);
	}
	args[i] = NULL;
	free(command_);
	return (args);
}
