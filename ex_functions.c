#include "shell.h"
/*
* print_ls - Function that prints String Elements
*/
size_t print_ls(const list_t *h)
{
size_t x = 0;
while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
x++;
}
return (x);
}
/*
* _puts - Function that print input string 
*/
void _puts(char *str)
{
int x = 0;
if (!str)
return;
while (str[x] != '\0')
{
_putchar(str[x]);
x++;
}
}
/**
 * _putchar - Function that writes character to stdout
 * @c: Printable character
 * Return: Sucess 1, Error -1, 
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

/**
 * starts_with - Function that checks if needle starts with haystack
 * @haystack: search Sting 
 * @needle: substring
 * Return: address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * is_delim - Function that checks character is delimeter or not 
 * @c: Checked Charcter 
 * @delim: string delimeter 
 * Return: true 1, false 0
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
