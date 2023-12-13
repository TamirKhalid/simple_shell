#include "shell.h"

/**
 *  * 
 *   */

void exit_h(char *cm)
{
if (_strcom("exit", cm) == 0)
{
free(cm);
exit(EXIT_SUCCESS);
}
}
