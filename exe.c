#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 *  exe_command: executes the user input
 */
/**
 *  * _strcpy: string copy
 *   * @des: string destination
 *    * @sr: argument source
 *     * Return: Vale of the string 
 *      */

char *_strcpy(char *des, char *sr)
{
	int y, len = 0;
	while (sr[len] != '\0')
	{
		len++;
	}
	for (y = 0; y < len; y++)
	{
		des[y] = sr[y];
	}
	des[y] = '\0';
	return (des);
}
/**
 *  * _strlen - function to determine the len of string
 *   * @str: string var
 *    * Return: length 
 *     */

int _strlen(char *str)
{
	int y = 0;
	while (*(str + y) != '\0')
	{
		y++;
	}
	return (y);
}
/**
 *  * _strcat:  attach the sr to des
 *   * @des: string destination 
 *    * @sr: string source
 *     * Return: string
 *      */

char *_strcat(char *des, char *sr)
{
	int len = 0, led = 0, z;
	while (sr[len] != '\0')
	{
		len++;
	}
	while (des[led] != '\0')
	{
		led++;
	}
	for (z = 0; z < len; z++)
	{
		des[led + z] = sr[z];
	}
	des[led + len] = '\0';
	return (des);
}

char *path_h(char **arg_value, char *user_in)
{
char *p;
p = malloc(_strlen("/bin/") + _strlen(user_in) + 1);
if (!p)
{
return (NULL);
}
_strcpy(p, "/bin/");
if (user_in[0] != '/' && user_in[0] != '.')
{
arg_value[0] = _strcat(p, user_in);
return (arg_value[0]);
}
free(p);
return (user_in);
}

void exe_command(const char *user_in) {
pid_t childpid = fork();
if (childpid == -1) {
perror("Error in forking.\n");
exit(EXIT_FAILURE);
} else if (childpid == 0) {

/*
 *Starting the child process
 *
 */

char *argu[130];
int argu_counter = 0;
extern char** environ;
char *token = strtok((char *)user_in, " ");
while (token != NULL) {
argu[argu_counter++] = token;
token = strtok(NULL, " ");
}
argu[argu_counter] = NULL;
argu[0] = path_h(argu, argu[0]);
execve(argu[0], argu, environ);
perror("Error executing.\n");
exit(EXIT_FAILURE);
} else {
wait(NULL);
}
}
