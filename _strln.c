#include "shell.h"

/**
 *  * _strln - length of a string
 *   * @s: string
 *    * Return: length
 *     */

int _strln(char *str)
{
int x = 0;
while (*(str + x) != '\0')
{
x++;
}
return (x);
}
