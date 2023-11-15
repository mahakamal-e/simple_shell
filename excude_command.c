#include "shell.h"
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

/**
 * reverseStr - reverses a string
 * @string: string
 * @length: length
 * Return: void
 */
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