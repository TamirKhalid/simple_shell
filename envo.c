#include "shell.h"

/**
 * env_p: prints the current environment.
 */
void tamstr(const char *format, const char *str){
    write(STDOUT_FILENO, show_m, strlen(show_m));
}
void env_p() {
extern char **environ;
char **envo;
for (envo = environ; *envo != NULL; envo++) {
tamstr("%s\n", *envo);
}
}
