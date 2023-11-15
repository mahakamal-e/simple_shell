#include "shell.h"
/**
 * print_on_prompt - print $ on stdin
 *
 */
void print_on_prompt(void)
{
	PRINTF("$ ");
}
/**
 * read_user_input - read input from user
 * Return: what function read
 */
char *read_user_input(void)
{
	ssize_t read_char;
	char *input_ = NULL;
	size_t size_line = 0;

	read_char = getline(&input_, &size_line, stdin);

	if (read_char == -1)
	{
		/*perror("Error: Failed to read input from user");*/
		free(input_);
		input_ = NULL;
	}
	return (input_);
}
/**
 * main - the core point for project
 * @argc: number of args
 * @argv: array of arguments
 * @envp: array of enviromental variabls
 * Return: 0 on SUCCESS
 */
int main(int __attribute__((__unused__))  argc, char **argv, char **envp)
{
	char *input_line;
	char **words_;
	int exit_status = 0;
	int countCmd = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		print_on_prompt();
		}
		input_line = read_user_input();
		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				print_on_prompt();
			}
			return (exit_status);
		}
		countCmd++;

		words_ = parse_string(input_line);
		if (words_ == NULL)
		{
			continue;
		}
		if (strcmp(words_[0], "exit") == 0)
		{
			exit(0);
		}
		else
		{
			exit_status = excute_command(words_, argv, envp, countCmd);
		}
	}
}
