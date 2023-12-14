#include "shell.h"
/*
 * * main: function
 * */

int main(void) {
	char *line;
	int status = 1;
	while (status) {
		display_prompt();
		line = read_line();
		if (!line)
	break;
	if (_strcmp(line, "env\n") == 0) {
	print_env();
	free(line);
	continue;
	}
	status = execute(line);
	free(line);
	}
	return 0;
}
