#include "shell.h"

/**
* env_p:  environment string print 
*
*/

void env_p(void)
{
int x = 0;
extern char **environ;
char **env = environ;
while (env[x])
{
write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
write(STDOUT_FILENO, "\n", 1);
x++;
}
}
