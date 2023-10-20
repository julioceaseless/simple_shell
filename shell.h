#ifndef SHELL_H
#define SHELL_H
#define DELIM " \t\r\n\a"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

extern char **environ;

/**
 * struct built_in - contain bultins to handle and function to excute
 * @command:pointer to char
 * @func:fun to excute when bultin true
 */
struct  built_in
{
	char *command;
	int (*func)(char **line, int errnum);
};
typedef struct built_in built_t;
char *_getline();
void free_env(char **env);
void *_realloc(void *ptr, unsigned int prev_size, unsigned int curr_size);
void _free(char **cmd_list, char *cmd);
char *append_path(char *command, char *path);
int check_cmd(char **cmd);
char **_token(char *cmd, char *delimiter);
int handle_built_in(char **cmd, int status);
int execute(char **cmd, char *input, int errnum, char **argv);
void my_exit(char **cmd, char *input, char *shell_name, int errnum);
int print_env(char **cmd, int errnum);
int change_dir(char **cmd, int errnum);
int bltn_lookup(char **cmd);
void my_perror(char *input, int errnum, char *shell_name);
void custm_perror(char *prog_name, int errnum, char **cmd);
char *_itoa(unsigned int num);
char *_strtok(char *str, const char *delim);
char *remove_space_padding(char *word);
void free_dbptr(char **ptr);
#endif
