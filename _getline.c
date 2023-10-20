#include "shell.h"
/**
 * _getline - function that reads input from file descripter
 * Return: pointer to a string input
 */
char *_getline()
{
	char *buffer = NULL, char_in = 0;
	int i = 0, buf_size = 1024, bytes_read;

	buffer = malloc(buf_size);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (char_in != EOF && char_in != '\n')
	{
		bytes_read = read(STDIN_FILENO, &char_in, 1);
		if (bytes_read < 0)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (bytes_read == 0)
			exit(EXIT_SUCCESS);
		buffer[i] = char_in;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return (NULL);
		}
		if (i >= buf_size)
		{
			buffer = _realloc(buffer, buf_size, (buf_size + 1));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
