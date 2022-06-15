#include "shell.h"

/**
 * free_list - free linked list
 * @head: linked list
 */

void free_list(list_t *head)
{
	while (head != NULL)
	{
		free(head->var);
		free(head);
		head = head->next;
	}
}
