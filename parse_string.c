#include "shell.h"
char **parse_string(char *line)
{
	char *token = NULL, *temp = NULL;
	char **tokens = NULL;
	int i = 0, j = 0;

	if (!line)
	{
		return (NULL);
	};
	temp = _my_strdup(line);
	token = strtok(temp, WHITESPACE);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, WHITESPACE);
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, WHITESPACE);
	while (token)
	{
		tokens[j] = _my_strdup(token);
		token = strtok(NULL, WHITESPACE);
		j++;
	}
	free(line), line = NULL;
	tokens[j] = NULL;
	return (tokens);
}

