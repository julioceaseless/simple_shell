#include "main.h"
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
	char delim[] = " ";
	char *home = _getenv("HOME");
	int ch_dir;

	cmd = token(args, delim);
	if (cmd != NULL && cmd[1] != NULL)
	{
		ch_dir = chdir(cmd[1]);
		if (ch_dir != 0)
		{
			perror("chdir");
			return;
		}
	}
	else
	{
		if (home != NULL)
		{
			chdir(home);
		}
		else
		{
			perror("chdir");
			return;
		}
	}
}
