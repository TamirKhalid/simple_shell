#include "shell.h"

/**
 * strln: function to get the length of a string
 * @str: The string
 * Return: String Lenght
 */

int _strln(char *str)
{
int x = 0;
while (*(str + x) != '\0')
{
x++;
}
return (x);
}
