#include "shell.h"

/**
 * read_user_input - read input from the user from stdin using gitline
 * Return: return what function read
 */
char *read_user_input(void)
{
	ssize_t read_char;
	char *input_ = NULL;
	size_t size_line = 0;

	if (isatty(STDIN_FILENO))
	{
		print_on_prompt();
	}

	read_char = getline(&input_, &size_line, stdin);

	if (read_char == -1)
	{
		perror("Error: Failed to read input from user");
		free(input_);
		input_ = NULL;
	}
	return (input_);
}
