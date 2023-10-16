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
	char *line = NULL, *str = NULL, *stripped_cmd = NULL;
	char **cmd_list = NULL;
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
			cmd_list = token(line, ";");/* split commands */
			while (*cmd_list != NULL)
			{
				stripped_cmd = remove_space_padding(*cmd_list);
				function = handle_built_in(stripped_cmd);
				if (function != NULL)
					function(stripped_cmd);
				else
					execute(stripped_cmd, argv[0]);
			cmd_list++;
			}
			free(stripped_cmd);
		}
	}
	free(line);
	return (0);
}
