#include "shell.h"
/*
 * _strlen - function to determine the len of string
 *  @str: string var
 *  Return: length 
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
