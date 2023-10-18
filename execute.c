#include "shell.h"
/**
 * execute - function to exexcute command from env
 * @args: command passed with arguments
 * @argv: name of program
 * Return: Void
 */
void execute(char *args, char *argv)
{
	pid_t child_pid;
	char *delim = " \t\n", *run = NULL, **env = environ;
	char *path = _getenv("PATH="), **cmd = token(args, delim);
	char **fullpaths = append_path(path, *cmd);
	int status, check = check_path(args);

	if (check == 0)
		run = find_command(fullpaths);
	else if (check == 1)
		run = find_command(cmd);

	if (run == NULL)
	{
		perror(*cmd);
		return;
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (child_pid == 0)
		{
			if (cmd == NULL || env == NULL)
				return;
			if (execve(run, cmd, env) == -1)
			{
				free_dbptr(cmd);
				perror(argv);
				exit(1);
			}
			else
			{
				free_dbptr(cmd);
				exit(0);
			}
		}
		else
			waitpid(child_pid, &status, 0);
	}
	free(path);
}
