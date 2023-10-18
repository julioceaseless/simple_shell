#include "shell.h"
/**
 * token - splits a string of commands into entries
 * @command: string of command + arguments
 * @delimeter: separater
 * Return: an array of strings
 */
char **token(char *command, char *delimiter)
{
    char **args = NULL;
    char *token = NULL;
    int i = 0;

    if (command == NULL || delimiter == NULL)
    {
        return NULL;
    }
    args = (char **)malloc(sizeof(char *));
    if (args == NULL)
    {
        perror("malloc");
        return NULL;
    }

    token = strtok(command, delimiter);
    while (token != NULL)
    {
        char **tmp = (char **)realloc(args, (i + 2) * sizeof(char *)); 
        if (tmp == NULL)
        {
            perror("realloc");
            free_dbptr(args);
            return NULL;
        }
        args = tmp;
        args[i] = malloc(strlen(token) + 1);
        if (args[i] == NULL)
        {
            perror("malloc");
            free_dbptr(args); 
            return NULL;
        }
        strcpy(args[i], token);
        args[i + 1] = NULL; 
        i++;
        token = strtok(NULL, delimiter);
    }
    return args;
}
