#include "shell.h"


void cmd_exit(info_t *data)
{
	(void) data;
	exit(errno);
}