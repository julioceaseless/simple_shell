#include "main.h"
/**
 * handle_built_in - matches command with its required function
 * @key: command
 * Return: nothing!
 */
void (*handle_built_in(char *key))(void)
{
	int i;
	built_t blt_array[] = {
		{"exit", my_exit},
		{"env", print_env},
		{NULL, NULL}
	};
	for (i = 0; blt_array[i].command != NULL; i++)
	{
		if (strcmp(key, blt_array[i].command) == 0)
		{
			return (blt_array[i].func);
		}
	}
	return (NULL);
}
