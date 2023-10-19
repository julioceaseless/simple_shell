#include "shell.h"
/**
 * print_env - Display Enviroment Variable
 * @cmd: command line arg but not utilized
 * @errnum: errnum count but not utilized
 * Return: Always 0
 */
int print_env(char **cmd, int errnum)
{
	char **env = environ;
	(void)cmd;
	(void)errnum;

	if (env == NULL)
		return (0);

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
	return (0);
}
