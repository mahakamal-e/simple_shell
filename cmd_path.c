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
