#include "main.h"
/**
 * token - splits a string of commands into entries
 * @command: string of command + arguments
 * @delimeter: separater
 * Return: an array of strings
 */
char **token(char *command, char *delimeter)
{
	char **args = NULL;
	char *token = NULL;
	char *buffer = NULL;
	char *command_ = NULL;
	int i = 0;

	command_ = strdup(command);
	/* get the first word */
	token = strtok(command_, delimeter);
	/* get the rest of the words */
	while (token != NULL)
	{
		buffer =  malloc(strlen(token) + 1);
		if (buffer == NULL)
		{
			perror("malloc");
			exit(1);
		}
		strcpy(buffer, token);
		args = realloc(args, (sizeof(char *)) * (i + 1));
		if (args == NULL)
		{
			perror("realloc");
			exit(1);
		}
		args[i] = buffer;
		i++;

		token = strtok(NULL, delimeter);
	}
	args[i] = NULL;
	free(command_);
	return (args);
}
