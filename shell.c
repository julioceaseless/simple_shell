#include "shell.h"
#include <signal.h>
/**
 * signal_handle - checks for signal
 * @signal: value of signal sent
 */
void signal_handle(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
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
	void (*function)(char *)

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

		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
			read--;
		}
		function = handle_built_in(line);
		if (function != NULL)
			function(line);
		else
		{
			execute(line, argv[0]);
		}
	}
	free(line);
	return (0);
}
