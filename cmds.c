#include"shell.h"
/**
 * handle_cmd - hanldes commands
 * @args: arguments
 */
void handle_cmd(char **args)
{
	int status = 0;

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
		execvp(args[0], args);
	}
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
