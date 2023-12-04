nclude "shell.h"

void read_in(char *user-in, size_t size) {
if (fgets(user-in, size, stdin) == NULL) {
if (feof(stdin)) {
tamo("\n");
exit(EXIT_SUCCESS);
} else {
tamo("Error input.\n");
exit(EXIT_FAILURE);
}
}
user-in[strcspn(user-in, "\n")] = '\0'; // this code line removes newline
}
