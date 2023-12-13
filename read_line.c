#include "shell.h"
/*
 * * read_line: function
 * */

char *read_line(void) {
char *line = NULL;
size_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1) {
free(line);
}
return NULL;
}
