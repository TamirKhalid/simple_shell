#include "shell.h"
/*
 *
 */

int _strncom(char *s1, char *s2, int num)
{
	if (!num)
		return (0);
	if (*s1 == *s2)
		return (*s1 ? _strncom(s1 + 1, s2 + 1, num - 1) : 0);
	if (*s1)
return (1);
if (*s2)
return (-1);
return (*s1 - *s2);
}
