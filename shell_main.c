#include "shell.h"

/*
 * main: This is the main function
 * user_in: lenght of user input string
 */

int main(void) {
char user_in[145];
while (true) {
dis_prompt();
read_in(user_in,i sizeof(user_in));
exe_command(user_in);
}
return 0;
}
