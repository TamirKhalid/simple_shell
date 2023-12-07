#include "shell.h"

/**
 *  * 
 */

char *_strcpy(char *des, char *sr)
{
int y, len = 0;
while (sr[len] != '\0')
{
len++;
}
for (y = 0; y < len; y++)
{
des[y] = sr[y];
}
des[y] = '\0';
return (des);
}
