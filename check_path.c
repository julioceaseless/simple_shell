#include "main.h"
/**
 * check_path - checks if command has full path
 * @command: command
 *
 * Return: 1 if path and 0 (no path)
 */
int check_path(const char *command)
{
	/* result = strchr(command, '/');*/
	if (*command == '/')
		return (1);
	return (0);
}
