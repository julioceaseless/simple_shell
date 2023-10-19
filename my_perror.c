#include "shell.h"
#define PRINTER(ptr) (write(STDOUT_FILENO, ptr, strlen(ptr)))

/**
 * my_perror - prints error based on the loops in the main
 * @input: input from user
 * @errnum: loop counter
 * @shell_name: name of the program file
 * Return: Nothing!
 */
void my_perror(char *input, int errnum, char *shell_name)
{
	char *err;

	PRINTER(shell_name);
	PRINTER(": ");
	err = _itoa(errnum);
	PRINTER(err);
	free(err);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
/**
 * custm_perror - print custom error message
 * @shell_name: name of the program file
 * @errnum: error counter
 * @cmd: command list
 * Return: Nothing!
 */
void custm_perror(char *shell_name, int errnum, char **cmd)
{
	char *err = _itoa(errnum);

	PRINTER(shell_name);
	PRINTER(": ");
	PRINTER(err);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(err);
}
