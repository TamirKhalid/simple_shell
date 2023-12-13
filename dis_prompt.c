#include "shell.h"

/**
 * dis_prompt:  display prompt
 * @argu: user argument
 * @ @envo: enviremental argument
 * @fg: flag argument 
 */

void dis_prompt(char **argu, char **envo, bool fg)
{
ssize_t nm = 0;
char *cm = NULL, *rgu[MAX_C];
int y;
while (1)
{
if (fg && isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", _strln("$ "));
if (nm == -1)
{
free(cm);
exit(EXIT_SUCCESS);
}
if (_strln(cm) == 0)
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
exe_h(rgu, argu, envo);
}
free(cm);
}
