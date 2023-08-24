#include"shell.h"
/**
 * get_line - reads line
 * @f: ..
 * @maxchar: ..
 * Return: char
 */
char *get_line(FILE *f, size_t maxchar)
{
	char *string = malloc(maxchar + 1);
	int c;
	size_t i, j;

	if (string)
	{
		while ((c = fgetc(f)) != EOF && c != '\n')
		{
			if (j < maxchar)
			{
				string[j++] = c;
				i++;
			}
		}
	}
	if (c == EOF && i == 0)
	{
		free(string);
		string = NULL;
	}
	else
	{
		string[j] = '\0';
	}
	return (string);
}
