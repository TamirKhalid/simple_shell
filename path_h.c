#include "shell.h"

/**
 *  path_h - path function handling
 *  @arg_value: argument value
 *  @user_in: user input 
 *  Return: the user input command for execute
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
