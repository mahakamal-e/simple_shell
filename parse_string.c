#include "shell.h"
char **tokenize(char *line)
{
	char *token = NULL, *temp = NULL;
	char **tokens = NULL;
	int i = 0, j = 0;

	if (!line)
	{
		return (NULL);
	};
	temp = strdup(line);
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
		tokens[j] = strdup(token);
		token = strtok(NULL, WHITESPACE);
		j++;
	}
	free(line), line = NULL;
	tokens[j] = NULL;
	return (tokens);
}
