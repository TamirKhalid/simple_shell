#include "shell.h"
/*
 * err_message - Function to get error message
 * @ernum: Error number
 * Return: error message
 */

char *err_message(int ernum) {
switch (ernum) {
case EACCES:
return "Permission denied";
case ENOENT:
return "No such file or directory";
default:
return "Unknown error";
}
}
/**
 * env_path - Function to get the PATH
 * Return: environment variable
 */
char *env_path(void) {
return getenv("PATH");
}
/**
 * dis_prompt - Function to display the prompt
 */
void dis_prompt(void) {
write(STDOUT_FILENO, "$ ", 2);
}
/**
 * srch_com -  search command Function 
 * @cmd: Command
 * @path: command path
 * Return: if found - Path to the command , NULL if not
 */
char *srch_com(char *cmd, char *path) {
char *token = strtok(path, ":");
char *cmd_path = NULL;
while (token != NULL) {
char tmp[MAX_ARG_LEN];
snprintf(tmp, sizeof(tmp), "%s/%s", token, cmd);
if (access(tmp, F_OK) == 0) {
cmd_path = strdup(tmp);
break;
}
token = strtok(NULL, ":");
}
return cmd_path;
}
/**
 * exe_h - Execute Function 
 * @line: User command 
 * Return: 0 or 1 
 */
int exe_h(char *line) {
char *args[MAX_ARGS + 1];
int arg_count = 0;
char *path;
char *cmd_path;
pid_t pid;
char *token;
line[strcspn(line, "\n")] = '\0'; 
token = strtok(line, " ");
while (token != NULL && arg_count < MAX_ARGS) {
args[arg_count++] = token;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (_strcmp(args[0], "exit") == 0) {
return 0; 
} else if (_strcmp(args[0], "env") == 0) {
p_env(); 
return 1;
}
path = env_path();
cmd_path = srch_com(args[0], path);
if (!cmd_path) {
char error_msg[200];
snprintf(error_msg, sizeof(error_msg), "%s: command not found\n", args[0]);
write(STDERR_FILENO, error_msg, _strlen(error_msg));
free(path);
return 1;				        }
pid = fork();
if (pid == 0) {
if (execve(cmd_path, args, NULL) == -1) {
char error_msg[200];
snprintf(error_msg, sizeof(error_msg), "%s: %s\n", args[0], err_message(errno));
write(STDERR_FILENO, error_msg, _strlen(error_msg));
exit(EXIT_FAILURE);
}
} else if (pid < 0) {
perror("Error");
} else {
wait(NULL);
}
free(path);
free(cmd_path);
return 1;
}
