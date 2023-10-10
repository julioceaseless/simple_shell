#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* prototypes */
void execute(char *args, char *argv);
char **token(char *command, char *delimeter);
char *find_command(char **paths);
char *_getenv(const char *name);
int check_path(const char *command);
char **append_path(char *path, char *command);
#endif
