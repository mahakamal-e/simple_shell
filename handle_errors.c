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
 * printCustomError - a function that used to print error message for exit
 * @command_name: the command name
 * @cmd_: command itself
 * @cmd_c: command count
 *
 * Return: void
 */
void printCustomError(char *command_name, char **cmd_, int cmd_c)
{
	char *command_count = _convert_int(cmd_c);

	PRINT_ERR(command_name);
	PRINT_ERR(": ");
	PRINT_ERR(command_count);
	PRINT_ERR(": Illegal number: ");
	PRINT_ERR(cmd_[1]);
	PRINT_ERR("\n");

	free(command_count);
}
