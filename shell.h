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
#define WHITESPACE " \t\r\n\a"
#define PRINT_ERR(c) (write(STDERR_FILENO, c, _my_strlen(c)))
#define PRINTF(str) (write(STDERR_FILENO, str, _my_strlen(str)))

extern char **environ;


/**
 * struct shellData - struct that store command array
 *
 * @arg_v: pointer to argv
 * @enviroment_: pointer to enviromental variables
 * @commad: array of command
 * @commad_length: counter
 * @_status: variable to store the statues of last excuted
 * Description: struct for store command line and env var
 */
typedef struct shellData
{
char **arg_v;
char **enviroment_;
char **commad;
int commad_length;
int _status;
} shell_data_t;

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
#endif
