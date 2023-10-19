#include "shell.h"
/**
 * append_path - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *append_path(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = strlen(value) + strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = strcat(cmd, value);
	cmd = strcat(cmd, "/");
	cmd = strcat(cmd, token);

	return (cmd);
}

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
