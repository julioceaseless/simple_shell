#include "main.h"
/**
 * execute - function to exexcute command from env
 * @args: command passed with arguments
 * @argv: name of program
 * Return: Void
 */
void execute(char *args, char *argv)
{
	pid_t child_pid;
	int status;
	char *delim = " ";
	char *path = _getenv("PATH=");
	char **cmd = token(args, delim);
	char **fullpaths = append_path(path, *cmd);
	char *run = NULL;
	char **env = environ;
	int check = check_path(args);

	if (check == 0)
		run = find_command(fullpaths);
	else
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
			execve(run, cmd, environ);
			perror(argv);
			exit(1);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
}
