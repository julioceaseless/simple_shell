#include "shell.h"
/**
 * my_exit - custom exit function to exit shell
 * @cmd_list: command list
 * @inpt_read: input from the user
 * @shell_name: name of the program file
 * @errnum: error count
 * Return: nothing!
 */
void my_exit(char **cmd_list, char *inpt_read, char *shell_name, int errnum)
{
    int i = 0;
    int exit_status

    if (cmd_list[1] == NULL)
    {
        free(inpt_read);
        free(cmd_list);
        exit(EXIT_SUCCESS);
    }

    while (cmd_list[1][i] != '\0')
    {
        if (isalpha(cmd_list[1][i]) != 0)
        {
            custm_perror(shell_name, errnum, cmd_list);
            break;
        }
        else
        {
	     exit_status = atoi(cmd_list[1]);

            if (exit_status < 0 || errnum == ENOENT)
            {
                free(inpt_read);
                free(cmd_list);
                _exit(2);
            }
            else
            {
                free(inpt_read);
                free(cmd_list);
                _exit(exit_status & 0xFF);
            }
        }
        i++;
    }
}
