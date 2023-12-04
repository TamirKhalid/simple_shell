#include "shell.h"
void exe_command(const char *user-in) {
pid_t childpid = fork();
if (childpid == -1) {
tamo("Error in the forking.\n");
exit(EXIT_FAILURE);
} else if (childpid == 0) {
// Child process
// Parse the command and its arguments
char *argu[130} /Maximum 128 arguments (adjust as needed)
int argu_counter=0;
char *token = strtok((char *)user-in, " ");
while (token != NULL) {
argu[argu_counter++] = token;
token = strtok(NULL, " ");
}
argu[argu_counter] = NULL; // Null-terminate the arguments array
// Execute the command
execvp(argu[0], argu);
// If execvp fails, print an error message
tamo("Error executing.\n");
exit(EXIT_FAILURE);
} else {
// Parent process
wait(NULL);
}
}
