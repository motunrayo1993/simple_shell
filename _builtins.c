#include "shell.h"
/**
 * _builtins - handles the shell builtins
 * @args: user's input
 * @env: enviroment linked list
 * Return: 0 or 1 if builtins, 2 if otherwise
 */
int _builtins(char **args, list_t **env)
{
	int i = 0;
	char *builtins[] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};

	while (builtins[i])
	{
		if (_strcmp(args[0], builtins[i]))
		{
			break;
		}
		i++;
	}
	switch (i)
	{
		case 1:
			free_double_ptr(args);
			return (0);
		case 0:
			cd_error(*env, _cd(args[1], env), args[1]);
			free_double_ptr(args);
			return (1);
		case 2:
			print_list(*env);
			free_double_ptr(args);
			return (1);
		case 3:
			set_env(env, args[1], args[2]);
			free_double_ptr(args);
			return (1);
		case 4:
			unset_env(env, args[1]);
			free_double_ptr(args);
			return (1);
		default:
			return (2);
	}
}
