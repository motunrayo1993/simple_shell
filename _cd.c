#include "shell.h"
/**
 * _cdonly - chdir if only cd is input
 * @env: environment linked list
 * Return: 0 if successful, -1 if otherwise
 */
int _cdonly(list_t **env)
{
	char *opwd, pwd[80];
	int i;

	getcwd(pwd, sizeof(pwd));
	set_env(env, "OLDPWD", pwd);
	opwd = get_env(*env, "HOME");
	i = chdir(opwd);
	free(opwd);
	return (i);
}
/**
 * _cd - change directory
 * @dir: destination directory
 * @env: environment linked list
 * Return: 0 if successful, 0 if otherwise
 */
int _cd(char *dir, list_t **env)
{
	char *ch;
	char pwd[80];
	int i = 0;

	getcwd(pwd, sizeof(pwd));
	if (dir == NULL)
		return	(_cdonly(env));

	switch (dir[0])
	{
		case '-':
			ch = get_env(*env, "OLDPWD");
			if (ch == NULL)
				_strcpy(ch, ".");
			else
			{
				chdir(ch);
				set_env(env, "OLDPWD", pwd);
				getcwd(pwd, sizeof(pwd));
				_puts(pwd);
				_putchar('\n');
				return (i);
			}
			break;
		case '~':
			ch = getenv("HOME");
			break;
		default:
			ch = dir;
			break;
	}

	set_env(env, "OLDPWD", pwd);
	i = chdir(ch);
	return (i);
}
