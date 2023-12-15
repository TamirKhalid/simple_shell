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
/**
 * add_node_end - Function that adds  node to the list
 * @head: head Note Address Pointer
 * @str: field of node strings
 * @num: History index
 * Return: Size
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;
if (!head)
return (NULL);
node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}
