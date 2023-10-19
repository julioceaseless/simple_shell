#include "shell.h"
/**
 * append_path - adds path to command
 * @command: shell command
 * @path: list of paths are retrieved from environment variable PATH
 *
 * Return: returns an array of full paths
 */
char *append_path(char *command, char *path)
{
	char *cmd;
	size_t len;

	len = strlen(path) + strlen(command) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = strcat(cmd, path);
	cmd = strcat(cmd, "/");
	cmd = strcat(cmd, command);

	return (cmd);
}
