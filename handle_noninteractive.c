#include "shell.h"
/**
 * non_interactive - a function that used to read command from file
 * @file_name: file name
 * @argv: array of args
 * @envp: array of enviromantal variables
 */
void non_interactive(char *file_name, char **argv, char **envp)
{
	char *input_line = NULL;
	size_t len = 0;
	ssize_t read_f;
	char **_words;
	int command_count = 0;
	FILE *file;

	if (file_name)
	{
		file = fopen(file_name, "r");
		if (!file)
		{
			perror("Error opening input file");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		file = stdin;
	}

	while ((read_f = getline(&input_line, &len, file)) != -1)
	{
		command_count++;
		if (read_f > 0 && input_line[read_f - 1] == '\n')
			input_line[read_f - 1] = '\0';
		_words = parse_string(input_line);
		if (_words)
		{
			excute_command(_words, argv, envp, command_count);
		}
	}
	free(input_line);
	fclose(file);


}
