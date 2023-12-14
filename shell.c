#include "shell.h"

/* Function to get error message based on error number */
char *get_error_message(int errnum) {
	    switch (errnum) {
	   	    case EACCES:
				                return "Permission denied";
						        case ENOENT:
						            return "No such file or directory";
							            default:
							                return "Unknown error";
	    }
}
	    char *get_env_path(void) {
		    return getenv("PATH");
	    }
	    void display_prompt(void) {
		    write(STDOUT_FILENO, "$ ", 2);
	    }
char *search_command(char *cmd, char *path) {
	char *token = strtok(path, ":");
	char *cmd_path = NULL;
	while (token != NULL) {
		char temp[MAX_ARG_LEN];
		snprintf(temp, sizeof(temp), "%s/%s", token, cmd);
		if (access(temp, F_OK) == 0) {
			cmd_path = strdup(temp);
			break;
		}
		token = strtok(NULL, ":");
	}
	return cmd_path;
}


/* Function to execute commands */
int execute(char *line) {
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
						print_env(); 
						return 1;
					}
					path = get_env_path();
					    cmd_path = search_command(args[0], path);
					    if (!cmd_path) {
			       char error_msg[200];
	            snprintf(error_msg, sizeof(error_msg), "%s: command not found\n", args[0]);
	            write(STDERR_FILENO, error_msg, _strlen(error_msg));
		    free(path);
		    return 1;
					        }
				    pid = fork();
		       if (pid == 0) {
	       if (execve(cmd_path, args, NULL) == -1) {
	char error_msg[200];
	          snprintf(error_msg, sizeof(error_msg), "%s: %s\n", args[0], get_error_message(errno));
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
