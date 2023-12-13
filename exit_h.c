#include "shell.h"

/**
 * exit_h: exit handling function
 * @user_in: the string to be read.
 * Return: nothing
 */

void exit_h(char *user_in)
{
if (_strcmp("exit", user_in) == 0)
{
free(user_in);
exit(EXIT_SUCCESS);
}
}
