#include "shell.h"
#include <signal.h>
/**
 * signal_handle - checks for signal
 * @signal: value of the signal sent
 */
void signal_handle(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}

/**
 * is_whitespace - checks if a string consists of only whitespace characters
 * @str: string to check
 * Return: 1 if the string contains only whitespace, 0 otherwise
 */
int is_whitespace(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace((unsigned char)(*str)))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: Always 0 Successg
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t read;
	char *line = NULL, *str = NULL;
	void (*function)(char *) = NULL;

	if (argc > 1)
	{
		str = remove_space_padding(stringfy(argv, argc));
		execute(str, argv[0]);
		free(str);
	}
	signal(SIGINT, signal_handle);
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		read = _getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("_getline");
			break;
		}
		if (read == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (is_whitespace(line))
			continue;
		if (read > 0 && line[read - 1] == '\n')
		{
			if (line[0] == '\n')
				continue;
			line[read - 1] = '\0';
			read--;
		}
		function = handle_built_in(line);
		(function == NULL) ? execute(line, argv[0]) : function(line);
	}
	free(line);
	return (0);
}
