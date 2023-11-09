#include "shell.h"
/**
 * excute_command - a function that used to excute a cmd
 * @command_: command
 * @argv: array of args
 * @envp: array of enviroments
 * @cmd_c: index command count
 *
 * Return: ws status
 */
int excute_command(char **command_, char **argv, char **envp, int cmd_c)
{

	pid_t pid;
	int _status;
	char *p_cmd;

	p_cmd = path_command(command_[0], envp);

	if (!p_cmd)
	{
		printNot_foundError(argv[0], command_[0], cmd_c);
		_free(command_);
		return (127);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execve(p_cmd, command_, envp) == -1)
			perror("Execve failed: unable to execute file");
		free(p_cmd);
		p_cmd = NULL;
		_free(command_);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &_status, 0) == -1)
			perror("waitpid() failed");
		free(p_cmd);
		p_cmd = NULL;
		_free(command_);
	}
	return (WEXITSTATUS(_status));
}
/**
 * _free - free of tokens
 * @input: to get free
 */
void _free(char **input)
{
	int iterat = 0;

	if (input == NULL)
	{
		return;
	}
	while (input[iterat])
	{
		free(input[iterat]);
		input[iterat] = NULL;
		iterat++;
	}
	free(input);
	input = NULL;
}
