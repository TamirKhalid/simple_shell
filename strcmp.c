#include "shell.h"

/**
 * 
 */

int _strcmp(char *stri, char *strii)
{
int cmp = 0;
while (*stri == *strii && *stri != '\0')
	{
stri++;
strii++;
}
if (stri != strii)
cmp = *stri - *strii;
return (cmp);
}
