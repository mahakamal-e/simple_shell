#include "shell.h"

/**
 * print_on_prompt - that function used to help to print dollar sign
 * instead of using printf
 *
 * Return: void
 */

void print_on_prompt(void)
{
	PRINTF("$");
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
/**
 * handle_signal - a function that use to prevent terminal end
 *
 * @s: signal inter
 *
 * Return: void
 */
void handle_signal(int s)
{
	if (s == SIGINT)
	{
		PRINTF("\n$ ");
	}
}
/**
 * _convert_int - a function that used to convert to ascii code
 *
 * @num: number that convert
 * Return: converted
 */
char *_convert_int(int num)
{
	char *_buffer = malloc(20);
	int iterat = 0;

	do {
		_buffer[iterat++] = (num % 10) + '0';
		num = num / 10;
	} while (num > 0);

	_buffer[iterat] = '\0';
	return (_buffer);
}
