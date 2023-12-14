#include "shell.h"
/**
 * env_p - Function that prints the enviroment
 * @stino: Struct Info
 * Return: 0
 */
int env_p(info_t *stino)
{
print_ls(stino->env);
return (0);
}
/**
 * _getenv - Function for Enviromental Variable value
 * @stino: Struct Info
 * @nm: Name of the enviromental Variable
 * Return: Value
 */
char *_getenv(info_t *stino, const char *nm)
{
list_t *node = stino->env;
char *p;
while (node)
{
p = starts_with(node->str, nm);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}
/**
 * _mysetenv - New Enviromntal Variable insilization,
 * @stino: Struct Info
 * Return: 0
 */
int _mysetenv(info_t *stino)
{
if (stino->argc != 3)
{
_mputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(stino, stino->argv[1], stino->argv[2]))
return (0);
return (1);
}
/**
 * _myunsetenv - Environment Variable Removal
 * @stino: Struct Info
 * Return: 0
 */
int _myunsetenv(info_t *stino)
{
int x;
if (stino->argc == 1)
{
_mputs("Too few arguements.\n");
return (1);
}
for (x = 1; x <= stino->argc; x++)
_unsetenv(stino, stino->argv[x]);
return (0);
}
