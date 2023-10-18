#include "shell.h"
#include <signal.h>
/**
 * read_handler - handles read output
 * @read: value of read system call
 * @line: line read from stdin
 * @argv: name of the program
 */
void read_handler(ssize_t read, char *line, char *argv[])
{
	char **cmd;
	void (*function)(char *) = NULL;
	int i = 0;

	if (read == -1)
	{
		perror("_getline");
		exit(1);
	}
	if (read == 0)
		exit(0);
	cmd = token(line, "\n");
	free(line);
	if (cmd == NULL)
		return;
	while (cmd[i] != NULL)
	{
		function = handle_built_in(cmd[i]);
		if (function == NULL)
			execute(cmd[i], argv[0]);
		else
			function(cmd[i]);
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

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

	if (argc > 1)
	{
		str = stringfy(argv, argc);
		execute(str, argv[0]);
		free(str);
	}

	signal(SIGINT, signal_handle);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = _getline(&line, &len, stdin);
		read_handler(read, line, argv);
	}
	return (0);
}

