#include "shell.h"

/**
 * env_p: prints the current environment.
 */

void tamstr(int f, const char *form, const char *val) {
while (*form != '\0') {
if (*form == '%' && *(form + 1) == 's') {
write(f, val, strlen(val));
form += 2;
} else {
write(f, form, 1);
form++;
}
}
}
void env_p() {
extern char **environ;
char **envo;
for (envo = environ; *envo != NULL; envo++) {
tamstr("%s\n", *envo);
}
}
