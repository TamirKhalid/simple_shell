#include "shell.h"

/**
 * main - Main Function 
 * @ac: counter argument 
 * @av: vector argument 
 * Return: success 0, error 1
 */

int main(int ac, char **av) {
info_t stino[] = {INFO_INIT};
int fd = 2;
fd = fd + 3;
if (ac == 2) {
fd = open(av[1], O_RDONLY);
if (fd == -1) {
if (errno == EACCES)
exit(126);
if (errno == ENOENT) {
_mputs(av[0]);
_mputs(": 0: Can't open ");
_mputs(av[1]);
_mputchar('\n');
_mputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
stino->readfd = fd;
}
pop_env_list(stino);
main_l(stino, av);
return (EXIT_SUCCESS);
}
