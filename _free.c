#include "shell.h"
/**
 * _free - free array of char ptr  and ptr
 * @cmd_list: pointer to strings
 * @cmd: ptr
 * Return: Nothing!
 */
void _free(char **cmd_list, char *cmd)
{
	free(cmd_list);
	free(cmd);
	cmd_list = NULL;
	cmd = NULL;
}
