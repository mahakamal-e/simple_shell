#include "shell.h"
char *_getEnvironment(char *variable, char **environment)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; environment[i]; i++)
	{
		tmp = strdup(environment[i]);
		key = strtok(tmp, "=");
		if (strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = strdup(value);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
