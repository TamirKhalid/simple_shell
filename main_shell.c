#include "shell.h"

/**
 * main: Main function of the program
 * @argc: Length argument 
 * @envo: Enviromental argument
 * @argu: User Argument
 * Renturn: 0
 */

int main(int argc, char **argu, char **envo)
{
bool intra = (argc == 1 && isatty(STDIN_FILENO));
dis_prompt(argu, envo, intra);
return (0);
}
