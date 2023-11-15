#include "shell.h"
/**
 * retain_EnvironmentV - responsible for retaining only
 * one specified environment variable
 * @var_: variable to keep
 * @env: environment variables.
 */
void retain_EnvironmentV(const char *var_, char **env)
{
	int iterat = 0;
	while (env[iterat] != NULL)
	{
		if (strncmp(env[iterat], var_, strlen(var_)) != 0 ||
				env[iterat][strlen(var_)] != '=')
		{
			env[iterat][0] = '\0';
		}
		iterat++;
	}
}
/**
 * print_nonEmpty - function that print non empty func
 * @env: env variables
 */
void print_nonEmpty(char **env)
{
	int iterat = 0;
	
	while (env[iterat] != NULL)
	{
		if (env[iterat][0] != '\0')
		{
			PRINTF(env[iterat]);
			PRINTF("\n");
		}
		iterat++;
	}

}
/**
 * displayEn - function excutes env command
 * @env: env variables
 */
void executeEnvCommand(char **env)
{
	printf("\nExecuting 'env':\n");
	execle("/usr/bin/env", "env", NULL, env);
}
