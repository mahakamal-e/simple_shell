#include "shell.h"
/**
 * parse_string - break input string into pieces
 *
 * @input_line: input string
 *
 * Return: array of broken down string (commands)
 */
char **parse_string(char *input_line)
{
	char **arr_str;
	char *token;
	int i_idx = 0;

	arr_str = malloc(8 * sizeof(char *));

	if (arr_str == NULL)
		perror("failed to allocate memory"), exit(1);

	token = strtok(input_line, DELIMITER_);

	while (token != NULL)
	{
		arr_str[i_idx] = _my_strdup(token);
		if (arr_str[i_idx] == NULL)
			perror("failed to allocate memory"), exit(1);
		i_idx++;

		token = strtok(NULL, DELIMITER_);
	}

	arr_str[i_idx] = NULL;
	return (arr_str);
}
