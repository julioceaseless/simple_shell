#include "shell.h"
/**
 * handle_built_in - matches command with its required function
 * @args: command
 * Return: nothing!
 */
void (*handle_built_in(char *args))(char *)
{
	int i;
	char delim[] = " ";
	char **cmd = NULL;
	built_t blt_array[] = {
		{"exit", my_exit},
		{"env", print_env},
		{"cd", change_dir},
		{NULL, NULL}
	};

	if (args == NULL)
		return (NULL);
	cmd = token(args, delim);
	if (cmd == NULL)
	{
		perror("token");
		return (NULL);
	}

	for (i = 0; blt_array[i].command != NULL; i++)
	{
		if (strcmp(*cmd, blt_array[i].command) == 0)
		{
			free(*cmd);
			return (blt_array[i].func);
		}
	}
	free(cmd);
	return (NULL);
}
