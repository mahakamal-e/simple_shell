#include "shell.h"
/**
 * check_builtin - a function that checks the command is built in
 *
 * @cmd_: input command from the user
 *
 * Return: On success 1 otherwise 0
 */
int check_builtin(char *cmd_)
{
	char *arr_builtin[] = {"env", "cd", "exit", NULL};

	int iterat = 0;

	while (arr_builtin[iterat])
	{
		if (_my_strcmp(arr_builtin[iterat], cmd_) == 0)
			return (1);
		iterat++;
	}
	return (0);
}
