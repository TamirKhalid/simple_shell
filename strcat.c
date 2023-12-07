#include "shell.h"

/**
 * 
 */

char *_strcat(char *des, char *sr)
{
int len = 0, led = 0, z;
while (sr[len] != '\0')
{
len++;
}
while (des[led] != '\0')
{
led++;
}
for (z = 0; z < len; z++)
{
des[led + z] = sr[z];
}
des[led + len] = '\0';
return (des);
}
