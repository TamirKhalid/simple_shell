#include "shell.h"
/*
 * exe_command : executes the user input
 */

void exe_command(const char *user_in) {
pid_t childpid = fork();
if (childpid == -1) {
tamo("Error in the forking.\n");
exit(EXIT_FAILURE);
} else if (childpid == 0) {

/*
 * Starting the child process
 */

char *argu[130];
int argu_counter=0;
char *token = strtok((char *)user_in, " ");
while (token != NULL) {
argu[argu_counter++] = token;
token = strtok(NULL, " ");
}
argu[argu_counter] = NULL;

/* Null terminates the arguments array */

/* Executing the command */

 execvp(argu[0], argu);

/* If executing fails, print an error */

tamo("Error executing.\n");
exit(EXIT_FAILURE);
} else {
wait(NULL);
}
}
