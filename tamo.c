#include "shell.h"
void tamo(const char *show_m) {
    write(STDOUT_FILENO, show_m, strlen(show_m));
}
