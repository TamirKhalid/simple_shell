#include "shell.h"
/*
 * main: Main function to run shell
 * Return: 0 when success
 */
int main(void) {
char *line;
int st = 1;
while (st) {
dis_prompt();
line = read_l();
if (!line)
break;
if (_strcmp(line, "env\n") == 0) {
p_env();
free(line);
continue;
}
st = exe_h(line);
free(line);
}
return 0;
}
