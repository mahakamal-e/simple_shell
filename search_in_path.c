#include "shell.h"

/**
 * searchInPath - a function that used to searche for the given command
 * in the directories specified in the PATH environment variable.
 *
 * @_cmd: command to search for
 * @path_cmd: representing the PATH environment variable
 *
 * Return: return the full path if the command found and NULL otherwise
 */
char *searchInPath(char *_cmd, char *path_cmd)
{
	char *copy_path;
	char *command_;
	char *link_;

	struct stat fileState;

	copy_path = _my_strdup(path_cmd);
	link_ = _my_strtok(copy_path, ":");

	while (link_ != NULL)
	{
		command_ = malloc(_my_strlen(link_) + _my_strlen(_cmd) + 2);

		if (command_ != NULL)
		{
			_my_strcpy(command_, link_);
			_my_strcat(command_, "/");
			_my_strcat(command_, _cmd);

			if (stat(command_, &fileState) == 0)
			{
				free(copy_path);
				return (command_);
			}
			free(command_);
		}
		link_ = _my_strtok(NULL, ":");
	}
	free(copy_path);
	return (NULL);
}
