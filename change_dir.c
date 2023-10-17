#include "shell.h"
/**
 * all_spaces - checks if a string contains only spaces
 * @str: string to be checked
 *
 * Return: 1 if true 0 if false
 *
 */
int all_spaces(char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * change_dir - changes directory
 * @args: arguments with directory to move to
 *
 * Return: void
 *
 */
void change_dir(char *args)
{
	char **cmd = NULL;
	char *delim = " ", *curr = _getenv("PWD=");
	char *home = _getenv("HOME="),  *old = _getenv("OLDPWD=");
	int ch_dir;

	cmd = token(args, delim);
	if (cmd != NULL && cmd[1] != NULL && !all_spaces(cmd[1]))
	{
		if (*cmd[1] == '-' && (strlen(cmd[1]) == 1))
		{
			ch_dir = chdir(old);
			if (ch_dir != 0)
			{
				perror("chdir");
				return;
			}
			setenv("OLDPWD", curr, 1);
			setenv("PWD", old, 1);
			printf("%s\n", curr);
		}
		else
		{
			ch_dir = chdir(cmd[1]);
			if (ch_dir != 0)
			{
				perror("cd");
				return;
			}
		}
	}
	else
	{
		if (home != NULL)
			chdir(home);
		else
		{
			perror("chdir");
			return;
		}
	}
}
