#include "shell.h"

/**
 * main_l - Shell Main Loop
 * @stino: Struct Info 
 * @av: Argument from main 
 * Return: Success 0, error 1
 */

int main_l(info_t *stino, char **av)
{
ssize_t z = 0;
int builtin_ret = 0;
int exited = 0;
while (!exited && (z != -1 && builtin_ret != -2))
{
clear_info(stino);
if (interactive(stino))
_puts("$ ");
_mputchar(BUF_FLUSH);
z = get_input(stino);
if (z != -1)
{
builtin_ret = find_builtin(stino);
if (builtin_ret == -1)
srch_cmd(stino);
}
else if (interactive(stino))
_putchar('\n');
if (!interactive(stino) && (stino->status || builtin_ret == -2))
exited = 1;
}
if (!exited) {
clear_info(stino);
}
if (!interactive(stino)) {
if (stino->err_num == -1)
exit(stino->status);
exit(stino->err_num);
}
return (builtin_ret);
}

/**
 * find_builtin - Command Buildin find function 
 * @stino: struct info 
 * Return: Not found -1, seccess 0, failed 1, exit -2.
 */
int find_builtin(info_t *stino)
{
int x, built_in_ret = -1;
builtin_table bt_table[] = {
{"exit", exit_m},
{"env", env_p},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{NULL, NULL}
};
for (x = 0; bt_table[x].type; x++)
if (_strcmp(stino->argv[0], bt_table[x].type) == 0)
{
stino->line_count++;
built_in_ret = bt_table[x].func(stino);
break;
}
return (built_in_ret);
}
/**
 * srch_cmd - Command path finder function
 * @stino: struct info
 * Return: void
 */
void srch_cmd(info_t *stino)
{
char *path = NULL;
int x, y;
stino->path = stino->argv[0];
if (stino->linecount_flag == 1)
{
stino->line_count++;
stino->linecount_flag = 0;
}
for (x = 0, y = 0; stino->arg[x]; x++)
if (!is_delim(stino->arg[x], " \t\n"))
y++;
if (!y)
return;
path = srch_path(stino, _getenv(stino, "PATH="), stino->argv[0]);
if (path)
{
stino->path = path;
fork_cmd(stino);
}
else
{
if ((interactive(stino) || _getenv(stino, "PATH=")
|| stino->argv[0][0] == '/') && is_exe(stino, stino->argv[0]))
fork_cmd(stino);
else if (*(stino->arg) != '\n')
{
stino->status = 127;
error_p(stino, "not found\n");
}
}
}
/**
 * fork_cmd - Forking Function
 * @stino: struct Info
 * Return: void
 */
void fork_cmd(info_t *stino)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(stino->path, stino->argv, ret_environ(stino)) == -1)
{
free_info(stino, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(stino->status));
if (WIFEXITED(stino->status))
{
stino->status = WEXITSTATUS(stino->status);
if (stino->status == 126)
error_p(stino, "Permission denied\n");
}
}
}
