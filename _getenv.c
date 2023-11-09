#include "shell.h"
/**
 * _getenv - gets the value of environment string pointed by name
 *
 * @name: containing the name of the requested variable.
 * @envp: array of enviromental variables.
 *
 * Return: the associated value to the string.
 */
char *_getenv(char *variable, char **environment)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environment[i]; i++)
	{
		tmp = _my_strdup(environment[i]);
		key = strtok(tmp, "=");
		if (_my_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _my_strdup(value);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
