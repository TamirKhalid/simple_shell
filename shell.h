#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_ARG_LEN 100

char *get_error_message(int errnum);
char *get_env_path(void);
void display_prompt(void);
char *search_command(char *cmd, char *path);
int execute(char *line);
void print_env(void);
char *read_line(void);
int _strcmp(char *stri, char *strii);
int _strlen(char *str);
#endif /* SHELL_H */
