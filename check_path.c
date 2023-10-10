#include "main.h"
/**
 * check_path - checks if command has full path
 * @command: command
 *
 * Return: 1 if path and 0 (no path)
 */
int check_path(const char *command)
{
	char *result = NULL;

	result = strchr(command, '/');
	if (result == NULL)
		return (0);
	return (1);
}
