#include "shell.h"
/**
 * get_environ - accesses the enviroment variables
 * Return: 0
 */
int get_environ(void)
{
	char *username = getenv("USERNAME");
	char *os = getenv("OS");
	char *path = getenv("PATH");

	if (username == NULL)
	{
		printf("USERNAME env var not found\n");
	}
	else
	{
		printf("Username: %s\n", username);
	}
	if (os == NULL)
	{
		printf("OS env var not found\n");
	}
	else
	{
		printf("Operating System: %s\n", os);
	}
	if (path == NULL)
	{
		printf("PATH env var not found\n");
	}
	else
	{
		printf("Path: %s\n", path);
	}
	return (0);
}
