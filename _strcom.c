#include "shell.h"

/**
 *
 */

int _strcom(char *t1, char *t2)
{
int com = 0;
while (*t1 == *t2 && *t1 != '\0')
{
t1++;
t2++;
}
if (t1 != t2)
com = *t1 - *t2;
return (com);
}
