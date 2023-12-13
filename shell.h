#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#define MAX_C 10

void dis_prompt(char **argu, char **envo, bool fg);
int _strcom(char *t1, char *t2);
char *_strct(char *des, char *sr);
char *path_h(char **rgu, char *cm);
char *_strcy(char *des, char *sr);
int _strln(char *str);
void exit_h(char *cm);
void exe_h(char **rgu, char **argu, char **envo);
extern char **environ;
#endif
