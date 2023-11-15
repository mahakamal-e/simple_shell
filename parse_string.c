#include "shell.h"
/**
 * parse_string - breaking down the input into small pieces
 * @str: input line from user (command)
 *
 * Return: pointer to array of broken command
 */
char **parse_string(char *input_line)
{
	char *single_token = NULL;
	char *temp_ = NULL;
	char **arr_str = NULL;
	int iterat = 0, iterat_;

	if (input_line == NULL)
		return (NULL);
	temp_ = strdup(input_line);

	single_token = strtok(temp_, " \t\n");

	if (single_token == NULL)
	{
		free(input_line);
		free(temp_);
		return (NULL);
	}

	while (single_token)
	{
		iterat++;
		single_token = strtok(NULL, " \t\n");
	}
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
		arr_str[iterat_] = strdup(single_token);
		single_token = strtok(NULL, " \t\n");
	}
	free(input_line);
	arr_str[iterat_] = NULL;
	return (arr_str);
}

