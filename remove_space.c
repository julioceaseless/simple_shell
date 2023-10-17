#include "shell.h"
/**
 * remove_space_padding - removes leading and trailing spaces
 * @word: pointer to the string that needs stripping
 * Return: pointer to stripped string
 */
char *remove_space_padding(char *word)
{
	int start = 0, end, len;
	int i = 0, j;
	char *new_word = NULL;

	if (word == NULL)
		return (NULL);
	/* remove space at the start */
	while (word[start] == ' ' || word[start] == '\t')
		start++;

	/* get length of word */
	for (len = 0; word[len] != '\0'; len++)
		;
	/* remove space at the end */
	end = len;
	while (word[end - 1] == ' ' || word[end - 1] == '\t')
		end--;

	/* copy string without space padding */
	new_word = malloc(end - start + 1);
	if (new_word == NULL)
	{
		perror("malloc");
		exit(98);
	}

	for (j = start; j < end; j++)
	{
		new_word[i] = word[j];
		i++;
	}
	new_word[i] = '\0';

	return (new_word);
}
