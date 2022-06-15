#include "shell.h"
/**
 * _realloc - reallocate space to a pointer
 * @str: pointer to pointer to be reallocated
 * @n: length of str
 */
void _realloc(char **str, int n)
{
	char *tmp = strdupe(*str);

	free(*str);
	*str = malloc(n);
	_strcpy(*str, tmp);
	free(tmp);
}
