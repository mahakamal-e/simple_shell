#include "shell.h"
/**
 * _my_exit - exit with arg
 * @arg: argument like 98
 */
void _my_exit(char **arg)
{
	int status = 0;
	int iterat = 0;

	if (arg[1] != NULL)
	{
		status = _atoi(arg[1]);
	}
	while (arg[iterat])
	{
		free(arg[iterat]);
		iterat++;
	}
	free(arg);
	exit(status);
}
