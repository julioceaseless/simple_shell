#include "main.h"
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
	char *line = NULL, *str = NULL, *parsed_line_unp = NULL;
	char **parsed_line = NULL;
	void (*function)(char *) = NULL;

	if (argc > 1)
	{
		str = remove_space_padding(stringfy(argv, argc));
		execute(str, argv[0]);
		free(str);
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
			parsed_line = token(line, ";");/* remove space paddings */
			while (*parsed_line != NULL)
			{
				parsed_line_unp = remove_space_padding(*parsed_line);
				function = handle_built_in(parsed_line_unp);
				if (function != NULL)
					function(parsed_line_unp);
				else
					execute(parsed_line_unp, argv[0]);
			parsed_line++;
			}
			free(parsed_line_unp);
		}
	}
	free(line);
	return (0);
}
