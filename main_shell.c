#include "shell.h"

/**
 *  * 
 *   */

int main(int argc, char **argu, char **envo)
{
bool intra = (argc == 1 && isatty(STDIN_FILENO));
dis_prompt(argu, envo, intra);
return (0);
}
