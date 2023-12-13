#include "shell.h"

/**
 * _strct: appending function
 * @des: destination argument
 * @sr: source argument
 * return: appended string
 */

char *_strct(char *des, char *sr)
{
int w = 0, z = 0, j;
while (sr[w] != '\0')
{
w++;
}
while (des[z] != '\0')
{
z++;
}
for (j = 0; j < w; j++)
{
des[z + j] = sr[j];
}
des[w + z] = '\0';
return (des);
}
