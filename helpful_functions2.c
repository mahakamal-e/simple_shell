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
/**
 * _my_strncmp - compare two strins up to the specific length
 * or find the differance
 *
 * @s1: first string
 * @s2: second string
 * @num: maximum numbers of character to compare between
 * Return: integer value the result of string comparison
 */
int _my_strncmp(char *s1, char *s2, size_t num)
{
	size_t iterat = 0;

	while (iterat < num)
	{
		if (s1[iterat] != s2[iterat])
			return (s1[iterat] - s2[iterat]);


		if (s1[iterat] == '\0' || s2[iterat] == '\0')
			return (s1[iterat] - s2[iterat]);
		iterat++;
	}
	return (0);
}
/**
 * _my_strtok -  breaks string str into a series of tokens
 * using the delimiter delim.
 * @str_: string that breaked
 * @delim_: This is the C string containing the delimiters
 * Return: a pointer to the first token found in the string
 * return NULL When there are no tokens left
 */
char *_my_strtok(char *str_, const char *delim_)
{
	return (strtok(str_, delim_));
}
