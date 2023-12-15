#include "shell.h"
/**
 * ret_environ - Function to return string copy of environ
 * @stino: Struct Info
 * Return: 0
 */
char **ret_environ(info_t *stino)
{
if (!stino->environ || stino->env_changed)
{
stino->environ = list_to_strings(stino->env);
stino->env_changed = 0;
}
return (stino->environ);
}
/**
 * _unsetenv - Function to Remove environment variables
 * @stino: Struct Info
 * Return: delete 1, else 0 
 */
int _unsetenv(info_t *stino, char *var)
{
list_t *node = stino->env;
size_t x = 0;
char *p;
if (!node || !var)
return (0);
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
stino->env_changed = delete_node_at_index(&(stino->env), x);
x = 0;
node = stino->env;
continue;
}
node = node->next;
x++;
}
return (stino->env_changed);
}
/**
 * _setenv - Function for new environment variable Initialization 
 * @stino: Struct Info
 * @var: property of enviromental variable
 * @value: value of the string
 * Return: 0
 */
int _setenv(info_t *stino, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;
if (!var || !value)
return (0);
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = stino->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
stino->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(stino->env), buf, 0);
free(buf);
stino->env_changed = 1;
return (0);
}
