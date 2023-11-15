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
	char *single_token = NULL;
	char *temp_ = NULL;
	char **arr_str = NULL;
	int iterat, iterat_;

	if (input_line == NULL)
		return (NULL);
	temp_ = _my_strdup(input_line);

	single_token = strtok(temp_, " \t\n");

	if (single_token == NULL)
	{
		free(input_line);
		free(temp_);
		return (NULL);
	}

	for (iterat = 0; single_token; iterat++)
		single_token = strtok(NULL, " \t\n");


	free(temp_);

	arr_str = malloc(sizeof(char *) * (iterat + 1));

	if (!arr_str)
	{
		free(input_line);
		return (NULL);
	}
	single_token = strtok(input_line, " \t\n");
	for (iterat_ = 0; single_token; iterat_++)
	{
		arr_str[iterat_] = _my_strdup(single_token);
		single_token = strtok(NULL, " \t\n");
	}
	free(input_line);
	arr_str[iterat_] = NULL;
	return (arr_str);
}
