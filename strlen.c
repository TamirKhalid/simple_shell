#include "shell.h"

/**
 * 
 */

int _strlen(char *str)
{
int y = 0;
while (*(str + y) != '\0')
{
y++;
}
return (y);
}
