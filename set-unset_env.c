#include"shell.h"
/**
 * setenv_cmd - sets the env var.
 * @var: variable
 * @val: value
 */
void setenv_cmd(char *var, char *val)
{
	if (setenv(var, val, 1) != 0)
	{
		fprintf(stderr, "Failed to set env. var.: %s\n", var);
	}
}
/**
 * unsetenv_cmd - unsets the env var
 * @var: variable
 */
void unsetenv_cmd(char *var)
{
	if (unsetenv(var) != 0)
	{
		fprintf(stderr, "Failed to unset env. var,: %s\n", var);
	}
}
