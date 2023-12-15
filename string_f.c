#include "shell.h"
/**
 * _strlen - Function that returns length of string
 * @s: Checked String 
 * Return: length
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
/**
 * _strcmp - Function that compare two strangs.
 * @s1: String first 
 * @s2: String Second
 * Return: if s1 < s2 (-), if s1 > s2 (+),if s1 == s2 (0)
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strcat - Function that concatenates two strings
 * @dest: String destitation
 * @src: String Source
 * Return: Buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
/**
 * _strcpy - Function that copy string
 * @dest: String destination
 * @src: String source
 * Return: Destination 
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
while (src[i])	{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
