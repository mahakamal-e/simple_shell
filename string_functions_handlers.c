#include "shell.h"
/**
 * _my_strcpy - function that used to copy the string
 *
 * @s1: destinaion stirng
 * @s2: source string
 *
 * Return: new copied string
 */
char *_my_strcpy(char *s1, char *s2)
{
	char *result_string = s1;

	while (*s2 != '\0')
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = '\0';
	return (result_string);
}

/**
 * _my_strcmp - compare two string
 *
 * @s1: first string s1
 * @s2: second dtring s2
 * Return: 0 if tow string identical otherwise return difference
 */
int _my_strcmp(char *s1, char *s2)
{
	int iterat = 0;
	int result = 0;

	while (s1[iterat] != '\0' && s2[iterat] != '\0')
	{
		if (s1[iterat] != s2[iterat])
		{
			result = s1[iterat] - s2[iterat];
			break;
		}
		iterat++;
	}
	return (result);
}

/**
 * _my_strcat - a function that concatenates two string
 *
 * @s1: first string
 * @s2: second dteing to concat
 * Return: result string
 */
char *_my_strcat(char *s1, char *s2)
{
	char *str = s1;

	while (*s1 != '\0')
	{
		s1++;
	}
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';

	return (str);
}

/**
 * _my_strdup - a function used to duplicated string
 *
 * @s: string that will dplicated
 * Return: Null if failed or duplicted string on success
 */
char *_my_strdup(char *s)
{
	int length = 0;
	int iterat;
	char *new_str;

	length = _my_strlen(s);

	new_str = malloc(sizeof(char) * (length + 1));

	if (new_str == NULL)
	{
		return (NULL);
	}
	for (iterat = 0; iterat <= length; iterat++)
	{
		new_str[iterat] = s[iterat];
	}
	return (new_str);
}
/**
 * _my_strlen - suncction used to get the lenght of string
 *
 * @str: input string
 * Return: return the num of bytes
 */
int _my_strlen(char *str)
{
	int iterat = 0;

	while (str[iterat] != '\0')
	{
		iterat++;
	}
	return (iterat);
}
