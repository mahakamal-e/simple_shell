#include "shell.h"
/**
 * handle_comm - handle the command enter from user to check if builtin
 *
 * @_words: spliting input line to words
 * @argv: array of args
 * @ex_st: status to exit with
 * @cmd_c: cmd count
 * @env: array of enviroments
 *
 * Return: void
 */
void handle_comm(char **_words, char **argv, int cmd_c, char **env)
{
	if (strcmp(_words[0], "exit") == 0) {
        printf("Exiting the shell...\n");
        exit(EXIT_SUCCESS);
    }
	else
	{
	excute_command(_words, argv, env, cmd_c);
	}

}
