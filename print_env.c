#include "shell.h"

/*
 * * print_env: function
 * */

void print_env() {
    extern char **environ;
    char **env;
	    for (env = environ; *env != NULL; env++) {
		 write(STDOUT_FILENO, *env, _strlen(*env));
		            write(STDOUT_FILENO, "\n", 1);
			        }
}
