#include "shell.h"
/**
 * execute - Excute Simple Shell Command (Fork,Wait,Excute)
 * @cmd:Parsed Command
 * @input: User Input
 * @errnum:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int execute(char **cmd, char *input, int errnum, char **argv)
{
	int status;
	pid_t child_pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (strncmp(*cmd, "./", 2) != 0 && strncmp(*cmd, "/", 1) != 0)
		{
			check_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			my_perror(cmd[0], errnum, argv[0]);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
