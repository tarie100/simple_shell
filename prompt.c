#include"shell.h"
#define BUFFER_SIZE 1024
char *our_getline(void)
{
	static char buf[BUFFER_SIZE];
	static int buf_pos;
	static int buf_len;
	char a, *str = NULL;
	int str_len = 0;

	if (buf_pos >= buf_len)
	{
		buf_len = read(0, buf, BUFFER_SIZE);
		buf_pos = 0;
		if (buf_len <= 0)
		{
			return (NULL);
		}
	}
	while (buf_pos < buf_len)
	{
		a = buf[buf_pos++];
		if (a == '\n')
		{
			break;
		}
		str = realloc(str, (str_len + 1) * sizeof(char));
		str[str_len++] = a;
	}
	if (str)
	{
		str = realloc(str, (str_len + 1) * sizeof(char));
		str[str_len] = '\0';
	}
	return (str);
}
/*char *(*charreader)(void) = our_getline;*/
/**
 * main - starting point
 * @argc: arg count
 * @argv: arg vector
 * Return: int
 */
int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *ptr;
	ssize_t charreader;
	size_t a = 0;
	char *ptrcpy = NULL;
	const char *delim = " \n";
	char *token;
	int i, tokens = 0;

	(void)argc;
	while (1)
	{
		printf("%s", prompt);
		charreader = getline(&ptr, &a, stdin);
		if (charreader == -1)
		{
			printf("Error reading input\n");
			return (-1);
		}
		/**
		 * if (ptr == NULL)
                {
		printf("error reading input\n");
		break;
		}*/
		ptrcpy = malloc(sizeof(char) * strlen(ptr));
		if (ptrcpy == NULL)
		{
			perror("Error allocating error");
			return (-1);
		}
		strcpy(ptrcpy, ptr);
		token = strtok(ptr, delim);
		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, delim);
		}
		tokens++;
		argv = malloc(sizeof(char *) * tokens);
		token = strtok(ptrcpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		cmd_exec(argv);
		printf("%s\n", ptr);
	}
	free(ptr);
	free(ptrcpy);
	return (0);
}
