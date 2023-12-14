#include "shell.h"

/*
 * p_env: function to print enviroment variable
 */

void p_env() {
extern char **environ;
char **env;
for (env = environ; *env != NULL; env++)
{
write(STDOUT_FILENO, *env, _strlen(*env));
write(STDOUT_FILENO, "\n", 1);
}
}
