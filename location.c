#include"shell.h"
/**
 * get_location - gets location
 * @cmd: command
 * Return: char
 */
char *get_location(char *cmd)
{
	char *path;
	char *pathcpy;
	int cmd_len, dir_len;
	char *tok_var, *full_path;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		pathcpy = strdup(path);
		cmd_len = strlen(cmd);
		tok_var = strtok(pathcpy, ":");
		while (tok_var != NULL)
		{
			dir_len = strlen(tok_var);
			full_path = malloc(cmd_len + dir_len + 2);
			strcpy(full_path, tok_var);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			strcat(full_path, "\0");
			if (stat(full_path, &buffer) == 0)
			{
				free(pathcpy);
				return (full_path);
			}
			else
			{
				free(full_path);
				tok_var = strtok(NULL, ":");
			}
		}
		free(pathcpy);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
