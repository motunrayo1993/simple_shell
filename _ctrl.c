#include "shell.h"
/**
 * ctrl_c - nullifies ctrl c
 * @n: signal
 */
void ctrl_c(int n)
{
	(void)n;
	_puts("\n$ ");
}
