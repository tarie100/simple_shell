#ifndef SHELL_H
#define SHELL_H
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;
extern int errno;

/*typedef struct information_t {
  char *file;
  char *line;
  char **args;*/
int launcher(char **args);
void printprompt(void);
char *our_readline(void);
void exit_shell(int status);
char *my_getline(void);
void cmd_exec(char **argv);
char *get_location(char *cmd);
int get_environ(void);
void setenv_cmd(char *var, char *val);
void unsetenv_cmd(char *var);
int mycd(char *info);
char *get_line(FILE *f, size_t maxchar);

/* Builtins */
void cmd_exit(info_t *data);

/** struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 
typedef struct builtin {
  char *cmd;
  int (*func)(info_t *);
} builtin;


char *type;
	int (*func)(info_t *);
};*/
  void (*func)(info_t *);
} builtin_t;
#endif
