#include "shell.h"
/**
 * stringfy - convert argument vector to string
 * @argv: argument vector
 * @argc: argument count
 *
 * Return: char pointer
 *
 */
char *stringfy(char *argv[], int argc)
{
	size_t total_length = 0;
	int i;
	char *str_array = NULL;

	if (argc <= 1)
	{
		return (NULL);
	}

	for (i = 1; i < argc; i++)
	{
		total_length += strlen(argv[i]);
	}
	total_length += argc - 2;
	str_array = malloc(total_length + 1);
	if (str_array == NULL)
	{
		return (NULL);
	}
	str_array[0] = '\0';
	for (i = 1; i < argc; i++)
	{
		strcat(str_array, argv[i]);
		if (i < argc - 1)
		{
			strcat(str_array, " ");
		}
	}
	return (str_array);
}
