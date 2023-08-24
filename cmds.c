#include"shell.h"
/**
 * handle_cmd - hanldes commands
 * @args: arguments
 */
void handle_cmd(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit_shell();
		exit(0);
	}
	if (strcmp(args[0], "ls") == 0)
	{
		execvp(args[0], args);
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] != NULL)
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
			else
			{
				fprintf(stderr, "cd: missing argument\n");
			}
		}
	}
}
/**
 * launcher - launches cmd & args
 * @args: arguments
 * Return: 0
 */
int launcher(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
