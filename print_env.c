#include "main.h"
/**
 * print_env - prints environment variables
 * Return: nothing
 */
void print_env(void)
{
	char **env = environ;

	if (env == NULL)
		exit(9);
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
