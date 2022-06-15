#include "shell.h"

/**
 * _getchar - gets a character from STDIN
 * Return: character gotten
 */
char _getchar(void)
{
	int i;
	char ch[1];

	ch[0] = '\0';
	i = read(STDIN_FILENO, ch, 1);
	if (i == 0)
	{
		if (isatty(STDIN_FILENO))
			_puts("\n");
		exit(0);
	}
	return (ch[0]);
}
/**
 * _getline - gets a line of no more than 1023 chars from STDIN
 * Return: line gotten
 */
char *_getline(void)
{
	char *line = malloc(1023);
	char ch;
	int i = 0;

	while (((ch = _getchar()) != '\n') && ((int)ch > 0) && (ch != '\0'))
	{
		*(line + i) = ch;
		i++;
	}
	*(line + i) = '\0';
	if (_strlen(line) == 0)
		return (NULL);
	_realloc(&line, _strlen(line) + 1);

	return (line);
}
/**
 * _putchar - displays a character on STDOUT
 * @c: character to print
 * Return: 1 if csuccessful
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _puts - print a string to STDOUT
 * @c: string to print
 */
void _puts(char *c)
{
	int i = 0;

	if (c == NULL)
		return;
	while (*(c + i))
	{
		_putchar(*(c + i));
		i++;
	}
}
