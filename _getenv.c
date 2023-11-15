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
	int iterat = 0;

	while (envp[iterat] != NULL)
	{
		if (strncmp(envp[iterat], name, strlen(name)) == 0 &&
		    envp[iterat][strlen(name)] == '=')
			return (&envp[iterat][strlen(name) + 1]);
		iterat++;
	}
	return (NULL);
}
