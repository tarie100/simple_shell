#include "shell.h"
/**
 * handle_cmd - hanldes commands
 * @args: arguments
 */
void handle_cmd(char **args)
{
	int status = 0;

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "cd: missing arg\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
	}
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
		}
		exit(status);
	}
	if (strcmp(args[0], "ls") == 0 && strcmp(args[1], "-l") == 0)
	{
		execv(args[0], args);
	}
}
int handle_builtin(info_t *data) { return (0); }
int handle_builtin(info_t *data) {
  builtin_t b[] = {{"exit", cmd_exit}, {NULL, NULL}};
  int i;

  for (i = 0; b[i].cmd; ++i) {
	if (strcmp(data->args[0], b[i].cmd) == 0)
	{
		b[i].func(data);
   		return (1);
	} 		
  }
  return (0);
}
