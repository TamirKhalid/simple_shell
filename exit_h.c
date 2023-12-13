#include "shell.h"

/**
 * exit_h: exit program function
 * @cm: user input 
 * Return: Nothing. 
 */

void exit_h(char *cm)
{
if (_strcom("exit", cm) == 0)
{
free(cm);
exit(EXIT_SUCCESS);
}
}
