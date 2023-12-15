#include "shell.h"
/*
 * exit_m - Funcion that exit shell 
 * @stino: Struct Info
 *Return: Exit status
 */
int exit_m(info_t *stino)
{
int exch;
if (stino->argv[1])
{
exch = _errti(stino->argv[1]);
if (exch == -1)
{
stino->status = 2;
error_p(stino, "Illegal number: ");
_mputs(stino->argv[1]);
_mputchar('\n');
return (1);
}
stino->err_num = _errti(stino->argv[1]);
return (-2);
}
stino->err_num = -1;
return (-2);
}
