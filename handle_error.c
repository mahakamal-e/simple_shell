#include "shell.h"

/**
 * printNot_foundError - a function that used to print not found
 *
 * @command_name: the name of command
 * @cmd_: command itself
 * @cmd_c: command count
 */
void printNot_foundError(char *command_name, char *cmd_, int cmd_c)
{
	char *command_count = _convert_int(cmd_c);

	PRINT_ERR(command_name);
	PRINT_ERR(": ");
	PRINT_ERR(command_count);
	PRINT_ERR(": ");
	PRINT_ERR(cmd_);
	PRINT_ERR(": not found\n");

	free(command_count);
}
/**
 * _convert_int - a function that used to convert to ascii code
 *
 * @num: number that convert
 * Return: converted
 */
char *_convert_int(int num)
{
	char *_buffer = malloc(20 * sizeof(char));
	int iterat = 0;

	do {
		_buffer[iterat++] = (num % 10) + '0';
		num = num / 10;
	} while (num > 0);

	_buffer[iterat] = '\0';
	return (_buffer);
}
