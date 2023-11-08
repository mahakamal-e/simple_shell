#include "shell.h"

/**
 * read_user_input - read input from the user from stdin using gitline
 * Return: return what function read
 */
char *read_user_input(void)
{
	ssize_t read_char;
	char *input_line = NULL;
	size_t size_line = 0;

	read_char = getline(&input_line, &size_line, stdin);

	if (read_char == -1)
	{
		perror("Error: Failed to read input from user");
		free(input_line);
		input_line  = NULL;
	}
	return (input_line);
}
