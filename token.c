#include "shell.h"
/**
 * token - splits a string of commands into entries
 * @command: string of command + arguments
 * @delimeter: separater
 * Return: an array of strings
 */
char **token(char *command, char *delimiter)
{
  char **args, **tmp, *token = NULL;
  int i = 0;

    if (command == NULL || delimiter == NULL)
      {
        return (NULL);
      }

    args = (char **)malloc(sizeof(char *));
    if (args == NULL)
      {
        perror("malloc");
        return (NULL);
      }

    token = strtok(command, delimiter);

    while (token != NULL)
      {
	tmp = (char **)realloc(args, (i + 1) * sizeof(char *));
        if (tmp == NULL)
	  {
            perror("realloc");
            free(args); 
            return (NULL);
	  }
        args = tmp;
	args[i] = (char *)malloc(strlen(token) + 1);
        if (args[i] == NULL)
	  {
            perror("malloc");
            return (NULL);
	  }
        strcpy(args[i], token);
        i++;
        token = strtok(NULL, delimiter);
      }
    tmp = (char **)realloc(args, (i + 1) * sizeof(char *));
    if (tmp == NULL)
      {
        perror("realloc");
        free(args); 
        return (NULL);
      }
    args = tmp;
    args[i] = NULL;
    return (args);
}
