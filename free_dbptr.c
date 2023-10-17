#include "shell.h"
/**
 * free_dbptr - frees double pointer
 * @ptr: double pointer
 */
void free_dbptr(char **ptr)
{
	int i = 0;

	for (; ptr[i] != NULL; i++)
		free(ptr[i]);
	free(ptr);
}


