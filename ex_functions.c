#include "shell.h"

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
/**
 * interactive - Function that returns when if shell is in interactive mode
 * @stino: Struct Info
 * Return: interactive mode 1, else 0
 */
int interactive(info_t *stino)
{
return (isatty(STDIN_FILENO) && stino->readfd <= 2);
}
