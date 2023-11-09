#include "shell.h"
/**
 * bultin_slctr - dispatcher choose which function to apply for builtin command
 * @cmds: command
 * @ex_st: the exit status the status that exit with
 * @en: environment array
 */
void bultin_slctr(char __attribute__((unused)) **cmds, int __attribute__((unused)) *ex_st, char **ev)
{
	if (_my_strcmp(cmds[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	else if (_my_strcmp(cmds[0], "env") == 0)
		_excuteEnv(cmds, ex_st, ev);
	
}

/**
 * _excuteEnv - excute the env command
 * @cmds: command
 * @ex_st: statust exit with
 * @ev: environment variables
 */
void _excuteEnv(char  __attribute__((unused)) **cmds, int  __attribute__((unused)) *ex_st, char **ev)
{
	int iterat = 0;

	while (ev[iterat])
	{
		PRINTF(ev[iterat]);
		PRINTF("\n");

		iterat++;
	}
	
}
