#include"shell.h"
/**
 * cmd_exec - executes cmd
 * @argv: arg vector
 */
void cmd_exec(char **argv)
{
	char *cmd = NULL;
	char *actual_cmd;

	if (argv)
	{
		cmd = argv[0];
		actual_cmd = get_location(cmd);
		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
