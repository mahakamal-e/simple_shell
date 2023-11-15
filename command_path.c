#include "shell.h"
char *searchInDirectory(char *cmd_);
char *searchInPath(char *_cmd, char *path_cmd);
/**
 * path_command - function that handle path for excutable command
 *
 * @cmd_: parsed input(command)
 * @envp: array of envp
 * Return: a pointer to a null-terminated string representing the full path
 * of the executable file that corresponds to the given command name.
 */
char *path_command(char *cmd_, char __attribute__((unused)) **envp)
{
	char *path_cmd;
	int iterat = 0;

	while (cmd_[iterat])
	{
		if (cmd_[iterat] == '/')
			return (searchInDirectory(cmd_));
		iterat++;
	}
	path_cmd = _getenv("PATH", envp);
	if (path_cmd == NULL)
		return (NULL);

	return (searchInPath(cmd_, path_cmd));
}
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
		return (strdup(cmd_));
	}
	return (NULL);
}
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

	copy_path = strdup(path_cmd);
	link_ = strtok(copy_path, ":");

	while (link_ != NULL)
	{
		command_ = malloc(strlen(link_) + strlen(_cmd) + 2);

		if (command_ != NULL)
		{
			strcpy(command_, link_);
			strcat(command_, "/");
			strcat(command_, _cmd);

			if (stat(command_, &fileState) == 0)
			{
				free(copy_path);
				return (command_);
			}
			free(command_);
		}
		link_ = strtok(NULL, ":");
	}
	free(copy_path);
	return (NULL);
}

