#include "shell.h"
/**
 * _realloc - resizes the block of memory using malloc
 * @ptr: pointer to be reallocated
 * @prev_size: this is the old size
 * @curr_size: this is the new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int curr_size)
{
	void *new_block;

	if (prev_size == curr_size)
		return (ptr);
	if (curr_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	new_block = malloc(curr_size);
	if (new_block == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		memset(new_block, '\0', curr_size);
		free(ptr);
	}
	else
	{
		memcpy(new_block, ptr, prev_size);
		free(ptr);
	}
	return (new_block);

}
