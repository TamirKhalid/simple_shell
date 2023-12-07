#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 *  exe_command: executes the user input
 */

void exe_command(const char *user_in) {
pid_t childpid = fork();
if (childpid == -1) {
perror("Error in forking.\n");
exit(EXIT_FAILURE);
} else if (childpid == 0) {

/*
 *Starting the child process
 *
 */

char *argu[130];
int argu_counter = 0;
extern char** environ;
char *token = strtok((char *)user_in, " ");
while (token != NULL) {
argu[argu_counter++] = token;
token = strtok(NULL, " ");
}
argu[argu_counter] = NULL;
char** environ;
argu[0] = path_h(argu, argu[0]);
execve(argu[0], argu, environ);
perror("Error executing.\n");
exit(EXIT_FAILURE);
} else {
wait(NULL);
}
}
