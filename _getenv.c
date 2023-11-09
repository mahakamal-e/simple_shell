#include "shell.h"
/**
 * _getenv - gets the value of environment string pointed by name
 *
 * @name: containing the name of the requested variable.
 * @envp: array of enviromental variables.
 *
 * Return: the associated value to the string.
 */
char *_getenv(char *name, char **envp)
{
	char *tmp, *key, *value, *env;
	int iterat = 0;

	while (envp[iterat])
	{
		tmp = _my_strdup(envp[iterat]);
		key = strtok(tmp, "=");
		if (_my_strcmp(key, name) == 0)
		{
			value = strtok(NULL, "\n");
			env = _my_strdup(value);
			free(tmp);
			tmp = NULL;
			return (env);
		}
		free(tmp);
		tmp = NULL;
		iterat++;
	}
	return (NULL);
}
