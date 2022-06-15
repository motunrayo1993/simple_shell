#include "shell.h"
/**
 * main - prompts user for input continuously until exit
 * Return: exit stat
 */
int main(void)
{
	list_t *env;
	int i;
	char **toks;
	char *line;
	int cmd_no = 0;

	createnvlist(&env);

	if (!(isatty(STDIN_FILENO)))
		_puts("$ ");
	while (1)
	{
		cmd_no++;
		if (isatty(STDIN_FILENO))
			_puts("$ ");
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c);
		toks = NULL;
		line = _getline();
		if (line == NULL)
		{
			continue;
		}
		toks = _strtok(line, ' ');
		i = _builtins(toks, &env);
		if (i == 1)
			continue;
		else if (i == 0)
			break;
		i = _execute(toks, env, cmd_no);
	}
	return (i);
}
