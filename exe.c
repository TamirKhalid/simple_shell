#include <shell.h>
#include <sys/types.h>

/*
 *  exe_command: executes the user input
 */

char *path_h(char **arg_value, char *user_in)
{
char *p;
p = malloc(_strlen("/bin/") + _strlen(user_in) + 1);
if (!p)
{
return (NULL);
}
_strcpy(p, "/bin/");
if (user_in[0] != '/' && user_in[0] != '.')
{
arg_value[0] = _strcat(p, user_in);
return (arg_value[0]);
}
free(p);
return (user_in);
}

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
argu[0] = path_h(argu, argu[0]);
execve(argu[0], argu, environ);
perror("Error executing.\n");
exit(EXIT_FAILURE);
} else {
wait(NULL);
}
}
