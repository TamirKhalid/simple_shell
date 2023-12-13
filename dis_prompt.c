#include "shell.h"

/**
 * 
 */

void dis_prompt(char **argu, char **envo, bool fg)
{
size_t i = 0;
ssize_t nm = 0;
char *cm = NULL, *rgu[MAX_C];
int y;
while (1)
{
if (fg && isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", _strlen("$ "));
if (nm == -1)
{
free(cm);
exit(EXIT_SUCCESS);
}
if (cm[nm - 1] == '\n')
cm[nm - 1] = '\0';
cm = trim(cm);
if (_strln(cd) == 0)
continue;
y = 0;
rgu[y] = strtok(cm, " \n");
exit_h(cm);
path_h(rgu, cm);
while (rgu[y])
{
y++;
rgu[y] = strtok(NULL, " \n");
}
runcm(rgu, argu, envo);
}
free(cm);
}
