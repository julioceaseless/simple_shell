#include "shell.h"

/**
 * _getenv - function to get the environment
 * @name: envirnment path variable
 *
 * Return: Full enevironment NULL if failed
 *
 */

char *_getenv(const char *name)
{
	char **env = environ, *value;
	int match;

	if (name == NULL || env == NULL)
	{
		return (NULL);
	}
	while (*env != NULL)
	{
		match = strncmp(*env, name, strlen(name));
		if (match == 0)
		{
			value = strdup(*env + strlen(name));
			if (value == NULL)
			{
				perror("strdup");
				return (NULL);
			}
			return (value);
		}
		env++;
	}
	return (NULL);
}
