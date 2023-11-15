#include "shell.h"
/**
 * _atoi - function that conver string to integer
 *
 * @s: string input
 * Return: converted value
 */
int _atoi(char *s)
{
	int iterat = 0;
	int conv_num = 0;

	while (s[iterat])
	{
		conv_num = conv_num * 10;
		conv_num = conv_num + (s[iterat] - '0');
		iterat++;
	}
	return (conv_num);
}
