#include "shell.h"
/**
 * bultin_slctr - dispatcher choose which function to apply for builtin command
 * @cmds: command
 * @argv: array of args
 * @ex_st: the exit status the status that exit with
 * @i_cmd: index of command
 * @ev: environment array
 */
void bultin_slctr(char **cmds, char **argv, int *ex_st, int i_cmd, char **ev)
{
	if (strcmp(cmds[0], "exit") == 0)
	{
		handleBuiltin_exit(cmds, argv, ex_st, i_cmd);
	}
	else if (strcmp(cmds[0], "env") == 0)
	{
		_excuteEnv(cmds, ex_st, ev);
	}
	else if (_my_strcmp(cmds[0], "cd") == 0)
	{
		handleBuiltin_cd(cmds, ex_st, ev);
	}

}

/**
 * _excuteEnv - excute the env command
 * @cmds: command
 * @ex_st: statust exit with
 * @ev: environment variables
 */
void _excuteEnv(char  __attribute__((unused)) **cmds, int *ex_st, char **ev)
{
	int iterat = 0;

	while (ev[iterat])
	{
		write(STDOUT_FILENO, ev[iterat], _strlen(ev[iterat]));
		write(STDOUT_FILENO, "\n", 1);

		iterat++;
	}
	_free(cmds);
	*ex_st = 0;

}

/**
 * handleBuiltin_cd - a function that used to handle cd
 * @cmds: command
 * @ex_st: exit status
 * @ev: environment
 */
void handleBuiltin_cd(char **cmds, int *ex_st, char **ev)
{
	char *dir;

	if (cmds[1] == NULL)
	{
		dir = _getenv("HOME", ev);
		if (dir != NULL)
			chdir(dir);
		else
		{
			PRINT_ERR("enviromental variable not set");
			 *ex_st = EXIT_FAILURE;
		}
	}
	else
	{
		if (chdir((const char *)cmds[1]) != 0)
		{
			perror("chdir");
			*ex_st = EXIT_FAILURE;
		}
	}
}
/**
 * handleBuiltin_exit - for exit builin
 *
 * @cmd_: command
 * @final_status: status exit with
 * @argv: array of args
 * @cmd_i: command index
 */
void handleBuiltin_exit(char **cmd_, char **argv, int *final_status, int cmd_i)
{
	int status_ = *final_status;

	if (cmd_[1] && check_digit(cmd_[1]))
	{
		status_ = _atoi(cmd_[1]);
	}
	else if (cmd_[1] && !check_digit(cmd_[1]))
	{
		printCustomError(argv[0], cmd_[1], cmd_i);
		*final_status = 2;
		return;
	}
	_free(cmd_);
	exit(status_);
}
