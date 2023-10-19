#include "shell.h"
/**
 * check_cmd -  searches command in path
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int check_cmd(char **cmd)
{
	char *path, *value, *cmd_;
	struct stat buf;

	path = getenv("PATH");
	value = strtok(path, ":");
	while (value != NULL)
	{
		cmd_ = append_path(*cmd, value);
		if (stat(cmd_, &buf) == 0)
		{
			*cmd = strdup(cmd_);
			free(cmd_);
			return (0);
		}
		free(cmd_);
		value = strtok(NULL, ":");
	}
	return (1);
}
