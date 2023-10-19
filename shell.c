#include "shell.h"
/**
 * _getline - function that reads input from file descripter
 * Return: pointer to a string input
 */
char *_getline()
{
	char *buffer = NULL;
	int i = 0, buf_size = 1024;
	ssize_t bytes_read;
	char char_in = 0;

	buffer = malloc(buf_size);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	while (char_in != EOF && char_in != '\n')
	{
		bytes_read = read(STDIN_FILENO, &char_in, 1);
		if (bytes_read == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
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
				return (NULL);
			}
		}
	i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
/**
 * signal_handle - checks for signal
 * @signal:Captured Signal
 */
void signal_handle(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 * Return: Always 0 Successg
 */
int main(int argc, char **argv)
{
	char *inpt_read, **cmd;
	int errnum = 0, func_status = 0;

	if (argc > 0)
	  /**	execute(argv[1], argv);*/
		signal(SIGINT, signal_handle);
	while (1)
	{
		errnum++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		inpt_read = _getline();
		if (inpt_read[0] == '\0')
			continue;

		cmd = _token(inpt_read);
		if (strcmp(*cmd, "exit") == 0)
			my_exit(cmd, inpt_read, argv[0], errnum);
		else if (bltn_lookup(cmd) == 0)
		{
			func_status = handle_built_in(cmd, func_status);
			_free(cmd, inpt_read);
			continue;
		}
		else
		      func_status = execute(cmd, inpt_read, errnum, argv);
		_free(cmd, inpt_read);
	}
	return (0);
}
