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


#define BUFFER_SIZE 1024
#define DELIMITER_ " \t\n"
#define PRINT_ERR(c) (write(STDERR_FILENO, c, _my_strlen(c)))
#define PRINTF(str) (write(STDERR_FILENO, str, _my_strlen(str)))

extern char **environ;




void print_on_prompt(void);

int _my_strlen(char *str);

char *_my_getline();

char *_my_strcpy(char *s1, char *s2);

int _my_strcmp(char *s1, char *s2);

char *_my_strcat(char *s1, char *s2);

char *_my_strdup(char *s);

void reverse_array(char *str, int len);

char *_convert_int(int num);

void handle_signal(int s);

char *read_user_input(void);

char **parse_string(char *input_line);


void handle_comm
(char **_words, char **argv, int *ex_st, int cmd_c, char **env);

int _atoi(char *s);

int check_digit(char *input_s);

void printNot_foundError(char *command_name, char *cmd_, int cmd_c);

void printCustomError(char *command_name, char *cmd_, int cmd_c);

int excute_command(char **command_, char **argv, char **envp, int cmd_c);

char *searchInDirectory(char *cmd_);

char *searchInPath(char *_cmd, char *path_cmd);

char *path_command(char *cmd_, char __attribute__((unused)) **envp);

int check_builtin(char *cmd_);

void bultin_slctr(char **cmds, char **argv, int *ex_st, int i_cmd, char **ev);
void _excuteEnv(char **cmds, int *ex_st, char **ev);
char *_getenv(char *name, char **envp);

void _free(char **input);


void *_memmove(void *dest, const void *src, size_t n);

int _my_strncmp(char *s1, char *s2, size_t num);


void _my_exit(char **arg);

void handleBuiltin_cd(char **cmds, int *ex_st, char **ev);

void handleBuiltin_exit
(char **cmd_, char **argv, int *final_status, int cmd_i);

void non_interactive(char *file_name, char **argv, char **envp);
char *_my_strtok(char *str_, const char *delim_);
#endif
