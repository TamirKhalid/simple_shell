#include "shell.h"
/*
 * main: This is the main function
 *
 */
int main(void) {
char user-in[145];
while (true) {
dis_prompt();
read_in(user-in, sizeof(user-in));
exe_command(user-in);
}
return 0;
}
