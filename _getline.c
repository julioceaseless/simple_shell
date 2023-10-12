#include "main.h"
/**
 * _getline - function that reads input from file descripter
 * @lineptr: pointer to line read
 * @n: size of space allocated to line
 * @stream: file descriptor to read from
 *
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf = NULL;
	ssize_t bytes_read;
	size_t total_bytes = 0;
	int count = 1, fd = fileno(stream);

	if (lineptr == NULL)
		return (-1);
	if (n == NULL)
		return (-1);
	buf = malloc(BUF_SIZE);
	if (buf == NULL)
	{
		perror("malloc");
		return (-1);
	}
	while ((bytes_read = read(fd, buf, BUF_SIZE)))
	{
		if (bytes_read < 0)
		{
			perror("read");
			return (-1);
		}
		total_bytes += bytes_read;
		if (buf[total_bytes - 1] == '\n')
			break;
		if (total_bytes > BUF_SIZE)
		{
			count++;
			buf = realloc(buf, (BUF_SIZE * count));
			if (buf == NULL)
			{
				perror("realloc");
				return (-1);
			}
		}
	}
	*lineptr = buf;
	*n = 120 * count;
	return (total_bytes);
}
