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
void handle_comm(char **_words, char **argv, int *ex_st, int cmd_c, char **env)
{
	if (check_builtin(_words[0]))
	{
		bultin_slctr(_words, argv, ex_st, cmd_c, env);
	}
	else
	{
		*ex_st = excute_command(_words, argv, env, cmd_c);
	}

}

/**
 * main - entry point for the program
 *
 * @argc: number of args
 * @argv: array of args
 * @env: array of enviromental variables
 *
 * Return: Alwayes return 0
 */

int main(int argc, char **argv, char **env)
{
	char *input_line;
	int exit_status = 0;
	int command_count = 0;
	char **_words;

	if (argc > 1)
	{
		non_interactive(argv[1], argv, env);
		return (EXIT_SUCCESS);
	}
	else if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			print_on_prompt();

			input_line = read_user_input();

			if (input_line == NULL)
			{
				print_on_prompt();
			}
			command_count++;
			_words = parse_string(input_line);
			if (!_words)
			{
				continue;
			}

			handle_comm(_words, argv, &exit_status, command_count, env);
			/*free(input_line);*/
		}
	}
	return (exit_status);
}
