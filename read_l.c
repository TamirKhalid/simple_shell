#include "shell.h"
/*
 * read_l: function that read user input
 * Return: return pointer to the function or Null when fail
 */
/* char *read_l(void) {
char *line = NULL;
  size_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1) {
free(line);
}
return NULL;
} */
char *read_l(void) {
    char *line = NULL;
    size_t bufsize = 0;
    if (getline(&line, &bufsize, stdin) == -1) {
        free(line); // Free allocated memory on failure
        return NULL; // Return NULL on failure
    }
    return line; // Return the read line
}
