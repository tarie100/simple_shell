#include "shell.h"
/**
 * cmd_exec - executes cmd
 * @argv: arg vector
 */
void cmd_exec(char **argv) {
  char *cmd = NULL;
  char *actual_cmd;
  int stat;
  pid_t pid;

  if (argv) {
    cmd = argv[0];
    actual_cmd = get_location(cmd);
    pid = fork();

    if (pid == 0) {
      if (execve(actual_cmd, argv, environ) == -1) {
        perror("Error:");
      }
    }

    if (pid > 0) {
      wait(&stat);
    }
  }
}
