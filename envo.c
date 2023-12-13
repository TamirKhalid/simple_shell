#include "shell.h"

/**
 * env_p : prints the current environment
 */


int env_p(char *env[]) {
int z = 0 ;
while (env[z] != NULL) {
int g = 0;
while (env[z][g] != '\0') {
g++;
}
write(STDOUT_FILENO, env[z], g); 
write(STDOUT_FILENO, "\n", 1);  
z++;
}
return 0;
}

