#include "shell.h"

/**
 * free_double_ptr - free malloced arrays
 * @str: array of strings
 */
void free_double_ptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/**
 * c_exit - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_list(env);
	exit(0);
}
/**
 * _execute - execute command user typed into shell
 * @toksArr: command user typed
 * @env: environmental variable
 * @num: nth user command; to be used in error message
 * Return: 0 on success
 */
int _execute(char **toksArr, list_t *env, int num)
{
	char *tmp;
	int status = 0, t = 0;
	pid_t pid;

	/* check if command is absolute path */
	if (access(toksArr[0], F_OK) == 0)
	{
		tmp = toksArr[0];
		t = 1;
	}
	/* else flesh out full path */
	else
		tmp = _which(toksArr[0], env);
	/* if not an executable, free */
	if (access(tmp, X_OK) != 0)
	{
		not_found(toksArr[0], num, env);
		free_double_ptr(toksArr);
		return (127);
	}
	else /* else fork and execute executable command */
	{
		pid = fork();
		if (pid == 0) /* if child process, execute */
		{
			if (execve(tmp, toksArr, NULL) == -1)
			{
				not_found(toksArr[0], num, env); /* special err msg */
				c_exit(toksArr, env);
			}
		}
		else /* if parent, wait for child then free all */
		{
			wait(&status);
			free_double_ptr(toksArr);
			if (t == 0)
				free(tmp);
		}
	}
	return (0);
}
