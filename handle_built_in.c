#include "shell.h"
/**
 * handle_built_in - handle built_in commands eg cd, env
 * @cmd: command list
 * @status: state of the last function
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handle_built_in(char **cmd, int status)
{
	built_t blt_array[] = {
		{"env", print_env},
		{"cd", change_dir},
		{NULL, NULL}
	};
	int i = 0;

	while (blt_array[i].command)
	{
		if (strcmp(cmd[0], blt_array[i].command) == 0)
			return (blt_array[i].func(cmd, status));
		i++;
	}
	return (-1);
}


