#include "shell.h"

void print_on_prompt(void)
{
	PRINTF("$ ");
}
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
int main(int ac, char **argv, char **environment)
{
	char *line, **tokens;
	int status = 0, indexNum = 0;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		print_on_prompt();
		}
		line = read_user_input();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (status);
		}
		indexNum++;

		tokens = tokenize(line);
		if (!tokens)
		{
			continue;
		}

			status = _execute(tokens, argv, environment, indexNum);
	
	}
}
