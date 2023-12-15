#include "shell.h"

/**
 * _memset - function that fills memory 
 *  @s: pointer to memory
 *  @b: byte fill *s
 *  @n: amount of bytes
 *  Return: a pointer to the memory 
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 *  _errti - converts string to integer
 *  @s: string 
 *  Return: 0 no numbers -1 on error
 */

int _errti(char *s)
{
int x = 0;
unsigned long int result = 0;
if (*s == '+')
s++;
for (x = 0;  s[x] != '\0'; x++)
{
if (s[x] >= '0' && s[x] <= '9')
{
result *= 10;
result += (s[x] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 *  error_p - function to prints err message
 *  @stino: struct info 
 *  @estr: string 
 *  Return: 0 if no numbers -1 on error
 */

void error_p(info_t *stino, char *estr)
{
_mputs(stino->fname);
_mputs(": ");
print_d(stino->line_count, STDERR_FILENO);
_mputs(": ");
_mputs(stino->argv[0]);
_mputs(": ");
_mputs(estr);
}

/**
 *   print_d - function prints a base 10 no
 *   @input: input
 *   @fd: filedescriptor
 *   Return: number 
 */

int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int x, count = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
__putchar = _mputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (x = 1000000000; x > 1; x /= 10)
{
if (_abs_ / x)
{
__putchar('0' + current / x);
count++;
}
current %= x;
}
__putchar('0' + current);
count++;
return (count);
}
