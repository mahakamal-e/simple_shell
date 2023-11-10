#include "shell.h"
/**
 * bultin_slctr - dispatcher choose which function to apply for builtin command
 * @cmds: command
 * @ex_st: the exit status the status that exit with
 * @ev: environment array
 */
void bultin_slctr(char **cmds, int *ex_st, char **ev)
{
	if (_my_strcmp(cmds[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_my_strcmp(cmds[0], "env") == 0)
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
		PRINTF(ev[iterat]);
		PRINTF("\n");

		iterat++;
	}
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
	if (cmds[1] == NULL)
	{
		char *dir = _getenv("HOME", ev);

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

