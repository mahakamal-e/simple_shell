#include "shell.h"

/**
 * searchInDirectory - sercha of current directory
 * @cmd_: command
 * Return: this function checks for the existence of a file specified
 * by the cmd parameter in the current directory. If the file exists,
 * it returns a duplicate of the file path; otherwise, it returns NULL.
 */
char *searchInDirectory(char *cmd_)
{
	/*struct stat used to store information about a file*/
	struct stat fileState;
	if (stat(cmd_, fileState) == 0)
	{
		return (_my_strdup(cmd_);
	}

	return (NULL);
}
/**
 * searchInPath - handle path that get from getenv function
 * @cmd_: command
 * @_path: the path
 * Return: if file exists return path of the file otherwise
 * return NULL
 */
char *searchInPath(char *cmd_, char *_path)
{
  
/**
 * path_command - handle path for excutable command
 * @cmd_: parsed input (command)
 * @envp: array of envp
 *
 * Return: a pointer to a null-terminated string representing the full path
 *  of the executable file that corresponds to the given command name
 *
 */
char *path_command(char *cmd_, char **envp)
{
	char *_path;
	int iterat = 0;

	while (cmd_[iterat])
	{
		if (cmd_[iterat] == '/')
			return (searchInDirectory(cmd_);
		iterat++;
	}
	_path = _getenv("PATH", envp);
	if (_path == NULL)
	{
	}
}
