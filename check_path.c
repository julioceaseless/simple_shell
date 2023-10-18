#include "shell.h"
/**
 * check_path - checks if command has full path
 * @command: command
 *
 * Return: 1 if path and 0 (no path)
 */
int check_path(char *command)
{
	char *result = NULL;
	char *delim = " \t\n";
	char **cmd = NULL;

	if (command == NULL)
		return (-1);

	cmd = token(command, delim);
	if (cmd == NULL)
		return (-1);

	result = strchr(*cmd, '/');

	if (result != NULL)
	{
		free_dbptr(cmd);
		return (1);
	}
	else
	{	free_dbptr(cmd);
		return (0);
	}
}
