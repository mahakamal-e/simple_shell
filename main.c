#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_child(char *command, int *pipe_fd, int prev_pipe) {
char *args[3];
	if (prev_pipe != -1) {
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}

	if (pipe_fd != NULL && pipe_fd[1] != -1) {
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}

	args[0] = command;
	args[1] = NULL;
	execvp(command, args);
	perror("exec failed");
	exit(EXIT_FAILURE);
}

void handle_pipe(char **commands) {
	int prev_pipe[2];
int i;
char *command;
pid_t pid;
 int pipe_fd[2];
 char *args[3];
	for ( i = 0; commands[i] != NULL; i++) {

		if (pipe(pipe_fd) == -1) {
			perror("pipe creation failed");
			exit(EXIT_FAILURE);
		}

		 pid = fork();
		if (pid == -1) {
			perror("fork failed");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			close(prev_pipe[1]);
			dup2(prev_pipe[0], STDIN_FILENO);
			close(prev_pipe[0]);

			close(pipe_fd[0]);
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[1]);

			command = commands[i];
			args[0] = command;
            args[1] = NULL;
			execvp(command, args);
			perror("exec failed");
			exit(EXIT_FAILURE);
		} else {
			close(prev_pipe[0]);
			close(prev_pipe[1]);
			prev_pipe[0] = pipe_fd[0];
			prev_pipe[1] = pipe_fd[1];
		}
	}
}

/*
void execute_child(char *command, int *pipe_fd, int prev_pipe) {
 
	if (prev_pipe != -1) {
        dup2(prev_pipe, STDIN_FILENO);
        close(prev_pipe);
    }

    if (pipe_fd != NULL && pipe_fd[1] != -1) {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
    }

    execlp(command, command, NULL); 
        perror("execvp failed");
        exit(EXIT_FAILURE);
    
}
void handle_pipe(char **commands) {
 int prev_pipe = -1;
    int pipe_fd[2];
    int i;
     pid_t pid;

    for (i = 0; commands[i] != NULL; i++){
        if (pipe(pipe_fd) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
	pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execute_child(commands[i], pipe_fd, prev_pipe);
        } else {
            waitpid(pid, NULL, 0);
	    close(pipe_fd[1]);
	    prev_pipe = pipe_fd[0];
        }
    }
}
*/
/**
 * handle_comm - handle the command enter from user to check if builtin
 *
 * @_words: spliting input line to words
 * @argv: array of args
 * @ex_st: status to exit with
 * @cmd_c: cmd count
 * @env: array of enviroments
 *
 * Return: void
 */
void handle_comm(char **_words, char **argv, int *ex_st, int cmd_c, char **env)
{
	int i = 0;
	int j, k;
	 char **pipe_commands_left;
	 char **pipe_commands_right;
	 int command_count = 0;
    while (_words[i] != NULL) {
        if (strcmp(_words[i], "|") == 0) {
	pipe_commands_left = malloc((i + 1) * sizeof(char *));
        pipe_commands_right = malloc((command_count - i) * sizeof(char *));

            for ( j = 0; j < i; j++) {
                pipe_commands_left[j] = _words[j];
            }
            pipe_commands_left[i] = NULL;

             k = 0;
            for ( j = i + 1; j < command_count; j++) {
                pipe_commands_right[k] = _words[j];
                k++;
            }
	    pipe_commands_right[command_count - i - 1] = NULL;
	    handle_pipe(pipe_commands_left);
	              free(pipe_commands_left);
            free(pipe_commands_right);

            return;
        }
        i++;
    }
	if (check_builtin(_words[0]))
	{
		bultin_slctr(_words, argv, ex_st, cmd_c, env);
	}
	else
	{
		*ex_st = excute_command(_words, argv, env, cmd_c);
	}

}

/**
 * main - entry point for the program
 *
 * @argc: number of args
 * @argv: array of args
 * @env: array of enviromental variables
 *
 * Return: Alwayes return 0
 */

int main(int argc, char **argv, char **env)
{
	char *input_line;
	int exit_status = 0;
	int command_count = 0;
	char **_words;

	if (argc > 1 || strcmp(argv[1], "|") == 0)
	{
		non_interactive(argv[1], argv, env);
		return (EXIT_SUCCESS);
	}
	else if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			print_on_prompt();

			input_line = read_user_input();

			if (input_line == NULL)
			{
				print_on_prompt();
			}
			command_count++;
			_words = parse_string(input_line);
			if (!_words)
			{
				continue;
			}

		
			handle_comm(_words, argv, &exit_status, command_count, env);
			free(input_line);
		}
	}
return (exit_status);

}
