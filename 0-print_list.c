#include <stdio.h>
#include "shell.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to linked list head
 * Return: amount of elements in the list
 */
size_t print_list(const list_t *h)
{
	size_t i;

	i = 0;
	while (h)
	{
		if ((h->var) == NULL)
		{
			write(1, "(nil)", 5);
		} else
		{
			write(1, h->var, _strlen(h->var));
		}
		write(1, "\n", 1);
		i++;
		h = h->next;
	}
	return (i);
}
