#include "shell.h"

/**
 * path_h: function that handle the path
 * @rgu: Argument
 * @cm: User command 
 * Return: Execution Command
 */

char *path_h(char **rgu, char *cm)
{
char *p;
p = malloc(_strln("/bin/") + _strln(cm) + 1);
if (!p)
{
return (NULL);
}
_strcy(p, "/bin/");
if (cm[0] != '/' && cm[0] != '.')
{
rgu[0] = _strct(p, cm);
return (rgu[0]);
}
free(p);
return (cm);
}
