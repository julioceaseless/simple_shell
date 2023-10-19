#include "shell.h"

/**
 * reverse - reverse array
 * @str: pointer to string to be reversed
 * @len: array length
 *
 */
void reverse(char *str, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = str[i];
		str[i] = str[(len - 1) - i];
		str[(len - 1) - i] = tmp;
	}
}
/**
 * int_length - get number of digits
 * @num: int to be used
 * Return: length
 */
int int_length(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * _itoa - Converts interger to ASCII
 * @num: number to convert
 * Return: pointer to string
 */
char *_itoa(unsigned int num)
{
	int len = 0, i = 0;
	char *str = NULL;

	len = int_length(num);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	while (num / 10)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[i] = (num % 10) + '0';
	reverse(str, len);
	str[i + 1] = '\0';
	return (str);
}
