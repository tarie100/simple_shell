#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * my_getline - reads line
 * Return: char
 */
char *my_getline(void) {
  static char buf[BUFFER_SIZE];
  static int buf_pos, buf_len;
  int str_len = 0;
  char a, *str = NULL;

  if (buf_pos >= buf_len) {
    buf_len = read(0, buf, BUFFER_SIZE);
    buf_pos = 0;
    if (buf_len <= 0) {
      return (NULL);
    }
  }
  while (buf_pos < buf_len) {
    a = buf[buf_pos++];
    if (a == '\n') {
      break;
    }
    str = realloc(str, (str_len + 1) * sizeof(char));
    str[str_len++] = a;
  }
  if (str) {
    str = realloc(str, (str_len + 1) * sizeof(char));
    str[str_len] = '\0';
  }
  return (str);
}

char **tokenize(char *line) {
  char *token, **argv;
  const char *delim = " \n";
  int tokens = 0, i;

  token = strtok(line, delim);
  while (token != NULL) {
    tokens++;
    token = strtok(NULL, delim);
  }
  tokens++;
  argv = malloc(sizeof(char *) * tokens);
  token = strtok(line, delim);
  for (i = 0; token != NULL; i++) {
    argv[i] = malloc(sizeof(char) * strlen(token));
    strcpy(argv[i], token);
    token = strtok(NULL, delim);
  }
  argv[i] = NULL;
  return (argv);
}

/**
 * main - starting point
 * @argc: arg count
 * @argv: arg vector
 * Return: int
 */
int main(int argc, char **argv)
{
	char *ptr, *token;
	char *prompt = "$ ";
	char *ptrcpy = NULL;
	ssize_t charreader;
	size_t a = 0;
	const char *delim = " \n";
	int i, tokens = 0;
	/*char **args, *home = "HOME";*/
	/*FILE *file = NULL;*/
	char *args[] = {"ls", "-l", "exit", "cd"};

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
	/*home = get_line(file, a);
	get_environ();
	setenv_cmd(home, "HOME");
	unsetenv_cmd(home);*/
	handle_cmd(args);
	free(ptr);
	free(ptrcpy);
	return (0);
}
int main(int argc, char **argv) {
  char *ptr;
  char *prompt = "$ ";
  char *ptrcpy = NULL;
  ssize_t charreader;
  size_t a = 0;
  int isBuiltin;
  int interractive = 0;
  info_t data = {NULL};

  data.file = argv[0];
	
  if (isatty(STDIN_FILENO))
    interractive = 1;

  (void)argc;
  while (1) {
    errno = 0;
    if (interractive)
      write(STDOUT_FILENO, "$ ", 2);
    charreader = getline(&ptr, &a, stdin);
    if (charreader == -1) {
      exit(errno);
    }
    ptrcpy = malloc(sizeof(char) * strlen(ptr));
    if (ptrcpy == NULL) {
      perror("Error allocating error");
      return (-1);
    }
	data.line = ptr;
    strcpy(ptrcpy, ptr);
    data.args = tokenize(ptr);
	isBuiltin = handle_builtin(&data);
	if (!isBuiltin)
   		cmd_exec(data.args);
  }
  free(ptr);
  free(ptrcpy);
  return (0);
}
