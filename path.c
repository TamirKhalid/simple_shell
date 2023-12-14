#include "shell.h"
/*
 * is_exe - function to define executable commands
 * @stino: Struct Info
 * @path: path to the file
 * Return: if true 1, else 0
 */
int is_exe(info_t *stino, char *path)
{
struct stat ste;
(void)stino;
if (!path || stat(path, &ste))
return (0);
if (ste.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
/*
 * ex_col - Function to execlude columes 
 * @pathst: String path
 * @strt: Index Start
 * @stp: Index Stop
 * Return: buffer return
 */
char *ex_col(char *pathst, int strt, int stp)
{
static char buf[1024];
int x = 0, y = 0;
for (y = 0, x = strt; x < stp; x++)
if (pathst[x] != ':')
buf[y++] = pathst[x];
buf[y] = 0;
return (buf);
}

/**
 * srch_path - Function to search command path
 * @stino: Struct Info
 * @pathst: String path
 * @cmd: Command
 * Return: Path or Null
 */
char *srch_path(info_t *stino, char *pathst, char *cmd)
{
int x = 0, cmdp = 0;
char *path;
if (!pathst)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_exe(stino, cmd))
return (cmd);
}
while (1)
{
if (!pathst[x] || pathst[x] == ':')
{
path = ex_col(pathst, cmdp, x);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_exe(stino, path))
return (path);
if (!pathst[x])
break;
cmdp = x;
}
x++;
}
return (NULL);
}
