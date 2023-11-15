#include "shell.h"
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
char *path_command(char *cmd, char **environment)
{
	char *pathEnv, *pathEnvCopy, *fullCmd, *directory;
	struct stat state;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &state) == 0)
				return (_my_strdup(cmd));
			return (NULL);
		}
	}
	pathEnv = _getenv("PATH", environment);
	if (!pathEnv)
		return (NULL);

	pathEnvCopy = _my_strdup(pathEnv), directory = strtok(pathEnvCopy, ":");
	while (directory)
	{
		fullCmd = malloc(_my_strlen(directory) + _my_strlen(cmd) + 2);
		if (fullCmd)
		{
			_my_strcpy(fullCmd, directory), _my_strcat(fullCmd, "/"), _my_strcat(fullCmd, cmd);
			if (stat(fullCmd, &state) == 0)
			{
				free(pathEnvCopy);
				free(pathEnv);
				return (fullCmd);
			}
			free(fullCmd);
		}
		directory = strtok(NULL, ":");
	}
	free(pathEnvCopy);
	free(pathEnv);
	return (NULL);
}
