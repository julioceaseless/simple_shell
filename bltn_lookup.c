#include "shell.h"
/**
 * bltn_lookup - handles built in
 * @cmd:command to check
 * Return: 0 Succes -1 otherwise
 */
int bltn_lookup(char **cmd)
{
	built_t check[] = {
		{"help", NULL},
		{"cd", NULL},
		{"history", NULL},
		{"echo", NULL},
		{"env", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
		return (-1);
	while (check[i].command)
	{
		if (strcmp(cmd[0], check[i].command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
