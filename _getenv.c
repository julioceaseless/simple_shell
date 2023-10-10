#include "main.h"

/**
 * _getenv - function to get the environment
 * @name: envirnment path variable
 *
 * Return: Full enevironment NULL if failed
 *
 */

char *_getenv(const char *name)
{
	char **env = environ;
	int match;

	if (name == NULL || env == NULL)
	{
		return (NULL);
	}	
	while (*env != NULL)
	{
		match = strncmp(*env, name, 5);
		if (match == 0)
		{
			return (*env + 5);
		}
		env++;
	}
	return (NULL);
}
