#include "shell.h"

/*
 *  * _strlen - function to determine the len of string
 *   *  @str: string var
 *    *  Return: length 
 **/

int _strlen(char *str)
{
	int y = 0;
	while (*(str + y) != '\0')
	{
		y++;
	}
	return (y);
}

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
