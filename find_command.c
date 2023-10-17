#include "shell.h"
#include <sys/stat.h>

/**
 * find_command - finds command in paths
 * @paths: array of full command paths to search in
 *
 * Return: path to where command was found or NULL if not found
 */
char *find_command(char **paths)
{
	struct stat st;
	int i = 0, found;

	if (paths == NULL)
		return (NULL);

	if (paths != NULL)
	{
		while (paths[i] != NULL)
		{
			found = stat(paths[i], &st);
			if (found == 0)
			{
				return (paths[i]);
			}
			i++;
		}
	}
	return (NULL);
}
