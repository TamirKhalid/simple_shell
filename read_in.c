#include "shell.h"
/*
 * read_in: User Command Input
 */
void read_in(char *user_in, size_t size) {
if (fgets(user_in, size, stdin) == NULL) {
if (feof(stdin)) {
tamo("\n");
exit(EXIT_SUCCESS);
} else {
tamo("Error input.\n");
exit(EXIT_FAILURE);
}
}
user_in[strcspn(user_in, "\n")] = '\0'; /* this code line removes newline */
}
