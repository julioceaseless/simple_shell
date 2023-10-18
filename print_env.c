#include "shell.h"
/**
 * print_env - prints environment variables
 * @args: argument passed
 *
 * Return: nothing
 */
void print_env(char *args)
{
	char **env = environ;

	(void)args;

	if (env == NULL)
		exit(9);
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
