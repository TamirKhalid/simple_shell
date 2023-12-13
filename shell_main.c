#include "shell.h"

/*
* main: main function
* user_in : user input variable
*/

int main() {
extern char **environ;
char user_in[1024];
while (true) {
dis_prompt();
read_in(user_in, sizeof(user_in));
if (strcmp(user_in, "exit") == 0) {
exit_h(user_in);
}else if (strcmp(user_in, "env") == 0) {
env_p(environ);
}else {
exe_command(user_in);
}
return 0;
}
}
