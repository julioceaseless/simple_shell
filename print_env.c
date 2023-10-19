#include "shell.h"
/**
 * print_env - Display Enviroment Variable
 * @cmd: command line args
 * @errnum: errnum count
 * Return: Always 0
 */
int print_env(__attribute__((unused)) char **cmd,
		__attribute__((unused)) int errnum)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
