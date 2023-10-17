#include "shell.h"
#include <sys/stat.h>
/**
 * append_path - adds path to command
 * @path: list of paths are retrieved from environment variable PATH
 * @command: shell command
 * Return: returns an array of full paths
 */
char **append_path(char *path, char *command)
{
	char **paths = NULL;
	char **full_paths = NULL;
	int i = 0, j = 0, num_of_paths = 0;

	if (path == NULL || command == NULL)
		return (NULL);
	paths = token(path, ":");
	if (paths == NULL)
	{
		perror("Token:");
		return (NULL);
	}
	while (paths[num_of_paths] != NULL)
		num_of_paths++;
	full_paths = malloc((num_of_paths + 1) * sizeof(char *));
	if (full_paths == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	for (; i < num_of_paths; i++)
	{
		full_paths[i] = malloc(strlen(paths[i]) +
				strlen(command) + 2);
		if (full_paths[i] == NULL)
		{
			for (; j < i; j++)
				free(full_paths[j]);
			perror("malloc");
			return (NULL);
		}
		strcpy(full_paths[i], paths[i]);
		strcat(full_paths[i], "/");
		strcat(full_paths[i], command);
	}
	for (i = 0; paths[i] != NULL; i++)
		free(paths[i]);
	free(paths);
	full_paths[num_of_paths] = NULL;
	return (full_paths);
}

