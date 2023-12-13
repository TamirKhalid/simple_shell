#include "shell.h"

/**
 * 
*/

char *_strcy(char *des, char *sr)
{
int x, l = 0;
while (sr[l] != '\0')
{
l++;
}
for (x = 0; x < l; x++)
{
des[x] = sr[x];
}
des[x] = '\0';
return (des);
}
