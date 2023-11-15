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

char *_convert_int(int num);
void printNot_foundError(char *command_name, char *cmd_, int cmd_c);

int _execute(char **cmd, char **argv, char **environment, int indexNum);

char **parse_string(char *input_line);

char *path_command(char *cmd_, char __attribute__((unused)) **envp);
char *searchInDirectory(char *cmd_);
char *searchInPath(char *_cmd, char *path_cmd);


void _free(char **input);
int excute_command(char **command_, char **argv, char **envp, int cmd_c);

char *_getenv(char *name, char **envp);

int _my_strlen(char *str);
char *_my_strcpy(char *s1, char *s2);
int _my_strcmp(char *s1, char *s2);
char *_my_strcat(char *s1, char *s2);
char *_my_strdup(char *s);
char *_my_strtok(char *str_, const char *delim_);
#endif
