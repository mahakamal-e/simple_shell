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

char **tokenize(char *str);

char *_handlePath(char *cmd, char **environment);

char *_getEnvironment(char *variable, char **environment);
#endif
