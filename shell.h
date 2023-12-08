#ifndef SHELL_H
#define SHELL_H
/*
 *  Header file created by: Morgan & Tamir
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

/*
 * Simple_Shell Prototypes
 */

void dis_prompt(void);
void tamo(const char *show_m);
void read_in(char *user_in, size_t size);
void exe_command(const char *user_in);
char *path_h(char **arg_value, char *user_in);
void exit_h(char *user_in);
void env_p();
char *_strcpy(char *des, char *sr);
int _strlen(char *str);
char *_strcat(char *des, char *sr);
int _strcmp(char *stri, char *strii);

#endif /* END */
