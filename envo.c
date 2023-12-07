#include "shell.h"

/**
 * env_p : prints the current environment
 */

void env_p() {
extern char **environ;
for (char **envo = environ; *envo != NULL; envo++) {
tamo("%s\n", *envo);
}
}
