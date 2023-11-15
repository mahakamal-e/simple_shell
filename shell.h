#ifndef SHELL_H
#define SHELL_H

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


#define PRINT_ERR(c) (write(STDERR_FILENO, c, strlen(c)))
#define PRINTF(str) (write(STDERR_FILENO, str, strlen(str)))
#define WHITESPACE " \t\n"

void freeArray(char **arr);
void printError(char *name, char *cmd, int indexNum);

char *_intToAscii(int n);

void reverseStr(char *string, int length);
int _execute(char **cmd, char **argv, char **environment, int indexNum);

char **parse_string(char *input_line);

char *path_command(char *cmd_, char __attribute__((unused)) **envp);
char *searchInDirectory(char *cmd_);
char *searchInPath(char *_cmd, char *path_cmd);

char *_getEnvironment(char *variable, char **environment);
#endif
