#include "main.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments
 *
 * Return: Always 0 Successg
 *
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	char *str = NULL;
	void (*function)(void) = NULL;

	if (argc > 1)
	{
		str = stringfy(argv, argc);
		execute(str, argv[0]);
	}
	else
	{
		while (1)
		{
			write(STDOUT_FILENO, "($) ", 4);
			read = _getline(&line, &len, stdin);
			if (read <= 0)
				exit(0);
			if (read > 0 && line[read - 1] == '\n')
			{
				line[read - 1] = '\0';
				read--;
			}
			function = handle_built_in(line);
			if (function != NULL)
				function();
			else
				execute(line, argv[0]);
		}
	}
	free(line);
	return (0);
}
