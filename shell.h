#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1




extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */

typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 **/

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
char **environ;
int env_changed;													int status;
char **cmd_buf;	
int readfd;
} info_t;

/*#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \  0, 0, 0} */


/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 **/

typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;



int main_l(info_t *, char **);
int find_builtin(info_t *);
void srch_cmd(info_t *);
void fork_cmd(info_t *);

int is_exe(info_t *, char *);
char *ex_col(char *, int, int);
char *srch_path(info_t *, char *, char *);

int loophsh(char **);
void _mputs(char *);
int _mputchar(char);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_memset(char *, char, unsigned int);
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _errti(char *);
void error_p(info_t *, char *);
int print_d(int, int);

int exit_m(info_t *);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int env_p(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int pop_env_list(info_t *);

char **ret_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_ls(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);


#endif
