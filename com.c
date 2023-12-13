#include "shell.h"

/*
 * _strncom: Comparing number of bytes in S1 & S2
 * @S1: String number one.
 * @S2: String Number two
 * @num: Bytes Number.
 * Return: if S2 is less than S1 return > 0,
 * 	   if S1 is less than S2 return < 0.
 * 	   Return 0 if S1 = S2. 
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
