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

/* Prototypes for functions */
char *err_message(int ernum);
char *env_path(void);
void dis_prompt(void);
char *srch_com(char *cmd, char *path);
int exe_h(char *line);
void p_env(void);
char *read_l(void);
int _strcmp(char *stri, char *strii);
int _strlen(char *str);

#endif /* SHELL_H */
