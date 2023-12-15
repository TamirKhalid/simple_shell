#include "shell.h"
/**
 *_mputs - Function that prints input string
 * @str: printed string 
 * Return: nothingg
 */
void _mputs(char *str)
{
int x = 0;
if (!str)
return;
while (str[x] != '\0')
{
_mputchar(str[x]);
x++;
}
}
/**
 * _mputchar - Function that writes character 
 * @c: Printed character 
 * Return: success 1, error -1, 
 */
int _mputchar(char c)
{
static int x;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
{
write(2, buf, x);
x = 0;
}
if (c != BUF_FLUSH)
buf[x++] = c;
return (1);
}
/**
 *_puts - Function that print input string
 *@str: Printed string 
 * Return: Null
 */
void _puts(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}
/**
 * _putchar - Function that writes character to stdout
 * @c: Printed Char
 * Return: success 1, error -1 
 */
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
