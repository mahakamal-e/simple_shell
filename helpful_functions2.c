#include "shell.h"
/**
 * check_digit - check if a string containes only digit characters
 *
 * @input_s: input  array of character
 *
 * Return: 0 if is digit and 1 if not
 */

int check_digit(char *input_s)
{
	int iterat = 0;

	if (input_s == NULL)
	{
		return (0);
	}

	while (input_s[iterat])
	{
		if (input_s[iterat] < '0' || input_s[iterat] > '9')
			return (0);

		iterat++;
	}
	return (1);
}
