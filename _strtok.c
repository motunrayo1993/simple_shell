#include "shell.h"
/**
 * strdupe - duplicates string
 * @str: parameter
 * Return: duplicate string
 */
char *strdupe(char *str)
{
	char *dup;
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(*dup) * (_strlen(str) + 1));
	while (i < _strlen(str))
	{
		*(dup + i) = *(str + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
/**
 * ignore_delimiters - skips through delimiters at the beginning of a file
 * @str: String to be operated upon
 */

void ignore_delimiters(char **str)
{
	char *node = *str;

	while (*node == ' ')
	{
		node++;
	}
	*str = node;
}
/**
 * t_length - computes length of a command
 * token from beginning index to next delimiting char
 * @str: string that contains the token
 * @idx: beginning index of the token string
 * @ch: delimiting char
 * Return: length of command
 */
int t_length(char *str, int idx, char ch)
{
	int len = 0;

	while (*(str + idx) != ch && *(str + idx) != '\0')
	{
		idx++;
		len++;
	}
	return (len);
}
/**
 * t_arraylength - computes total length of input string ignoring multiple
 * continuous delimiters
 * @str: input string
 * @ch: delimiter
 * Return: computed length
 */
int t_arraylength(char *str, char ch)
{
	int i = 0, len = 0;

	while (*(str + i))
	{
		if ((*(str + i) == ch) && (*(str + i + 1) == ch))
		{
			i++;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}
/**
 * _strtok - tokenizes string
 * @str: input string
 * @ch: delimiter
 * Return: token array
 */
char **_strtok(char *str, char ch)
{
	char **toks = NULL;
	int len, i  = 0, j = 0, ptr = 0;
	int tokArr_sz;

	ignore_delimiters(&str);
	tokArr_sz = t_arraylength(str, ch);
	toks = malloc(sizeof(char *) * (tokArr_sz + 2));
	if (toks == NULL)
		return (NULL);

	while (i < tokArr_sz)
	{
		if (str[i] != ch)
		{
			len = t_length(str, i, ch);
			toks[ptr] = malloc(sizeof(ch) * (len + 1));
			if (toks[ptr] == NULL)
				return (NULL);
			j = 0;
			while ((str[i] != ch) && (str[i] != '\0'))
			{
				toks[ptr][j] = str[i];
				i++;
				j++;
			}
			toks[ptr][j] = '\0';
		}
		if (i < tokArr_sz && (str[i + 1] != ch) && (str[i + 1] != '\0'))
			ptr++;
		i++;
	}
	ptr++;
	toks[ptr] = NULL;
	return (toks);

}
