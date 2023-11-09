#include "shell.h"

/**
 * searchInDirectory - search in the currentcurrent directory
 * @cmd_: command
 * Return: this function checks for the existence of a file specified
 * by the cmd parameter in the current directory. If the file exists,
 * it returns a duplicate of the file path; otherwise, it returns NULL.
 */
char *searchInDirectory(char *cmd_)
{
	/*struct stat used to store information about a file*/
	struct stat fileState;

	if (stat(cmd_, &fileState) == 0)
	{
		return (_my_strdup(cmd_));
	}
	return (NULL);
}
