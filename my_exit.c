#include "main.h"
/**
 * my_exit - exits shell
 * @args: argument passed
 *
 * Return: nothing!
 */
void my_exit(char *args)
{
	int stat;
	char delim[] = " ";
	char **cmd = NULL;

	cmd = token(args, delim);

	if (cmd[1] == NULL)
	{
		_exit(0);
	}
	stat = atoi(cmd[1]);

	fflush(NULL);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	_exit(stat);
}
