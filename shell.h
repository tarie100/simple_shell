#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<fcntl.h>
#include<stdint.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#include<stdarg.h>
void handle_cmd(char **args);
int launcher(char **args);
void printprompt(void);
char *our_readline(void);
void exit_shell(void);
char *my_getline(void);
void cmd_exec(char **argv);
char *get_location(char *cmd);
int get_environ(void);
void setenv_cmd(char *var, char *val);
void unsetenv_cmd(char *var);
#endif
