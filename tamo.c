#include "shell.h"

/*
 * tamo: function to print the message
 */

void tamo(const char *show_m) {
    write(STDOUT_FILENO, show_m, strlen(show_m));
}
