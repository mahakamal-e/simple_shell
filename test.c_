#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

#define WHITESPACE " \t\n"

char *_handlePath(char *cmd, char **environment);
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

/**
 * readline - reads a line of text from STDIN
 * Return: string
 */

char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line), line = NULL;
	}

	return (line);
}
void reverseStr(char *string, int length)
{
	char temp;
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}
}
char *_intToAscii(int n)
{
	char buffer[25];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverseStr(buffer, i);

	return (strdup(buffer));
}
void printError(char *name, char *cmd, int indexNum)
{
	char *index, errMessage[] = ": not found\n";

	index = _intToAscii(indexNum);
	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, errMessage, strlen(errMessage));

	free(index);
}
void freeArray(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	};
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	};
	free(arr), arr = NULL;
}
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
int _execute(char **cmd, char **argv, char **environment, int indexNum)
{
	char *fullCmd;
	pid_t childProcess;
	int status;

	fullCmd = _handlePath(cmd[0], environment);

	if (!fullCmd)
	{
		printError(argv[0], cmd[0], indexNum);
		freeArray(cmd);
		return (127);
	}
	childProcess = fork();
	if (childProcess == 0)
	{
		if (execve(fullCmd, cmd, environment) == -1)
		{
			perror("execve");
		}
		free(fullCmd), fullCmd = NULL;
		freeArray(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(childProcess, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free(fullCmd), fullCmd = NULL;
		freeArray(cmd);
	}
	return (WEXITSTATUS(status));
}
/**
 * _handlePath - handles the path
 * @cmd: command
 * @environment: environment
 * Return: path
 */

char *_handlePath(char *cmd, char **environment)
{
	char *pathEnv, *pathEnvCopy, *fullCmd, *directory;
	struct stat state;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &state) == 0)
				return (strdup(cmd));
			return (NULL);
		}
	}
	pathEnv = _getEnvironment("PATH", environment);
	if (!pathEnv)
		return (NULL);

	pathEnvCopy = strdup(pathEnv), directory = strtok(pathEnvCopy, ":");
	while (directory)
	{
		fullCmd = malloc(strlen(directory) + strlen(cmd) + 2);
		if (fullCmd)
		{
			strcpy(fullCmd, directory), strcat(fullCmd, "/"), strcat(fullCmd, cmd);
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
int main(int ac, char **argv, char **environment)
{
	char *line, **tokens;
	int status = 0, indexNum = 0;
	(void)ac;

	while (1)
	{
		line = readline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (status);
		}
		indexNum++;

		tokens = tokenize(line);
		if (!tokens)
		{
			continue;
		}

		/*if (isBuiltIn(tokens[0]))
		{
			handleBuiltIn(tokens, argv, &status, indexNum, environment);
		}
		else
		{*/
			status = _execute(tokens, argv, environment, indexNum);
		
	}
}
