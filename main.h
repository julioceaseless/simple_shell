#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUF_SIZE 120
/**
 * struct built_in - function pointer struct
 * @command: pointer to command typed
 * @func: pointer to function
 */
struct built_in
{
	char *command;
	void (*func)(char *);
};
typedef struct built_in built_t;
extern char **environ;
/* prototypes */
void execute(char *args, char *argv);
char **token(char *command, char *delimeter);
char *find_command(char **paths);
char *_getenv(const char *name);
int check_path(const char *command);
char **append_path(char *path, char *command);
char *stringfy(char *argv[], int argc);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
/* Shell built in  */
void (*handle_built_in(char *key))(char *);
void print_env(char *args);
void my_exit(char *args);
void change_dir(char *args);
#endif
