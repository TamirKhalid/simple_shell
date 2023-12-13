#include "shell.h"
/**
 *
 */

void exe_h(char **rgu, char **argu, char **envo)
{
pid_t mychild;
int st;
mychild = fork();
if (mychild == -1)
{
perror("Execution Error");
exit(EXIT_FAILURE);
}
if (mychild == 0)
{
if (execve(rgu[0], rgu, envo) == (-1))
{
write(STDOUT_FILENO, argu[0], _strln(argu[0]));
write(STDOUT_FILENO, ": No such file or directory",
_strln(": No such file or directory"));
write(STDOUT_FILENO, "\n", 1);
}
exit(EXIT_FAILURE);
}
else
{
wait(&st);
}
}
