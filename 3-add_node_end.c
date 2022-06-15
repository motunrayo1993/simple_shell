#include "shell.h"
#include <string.h>
#include <stdlib.h>


/**
 * add_node_end - add node to end of linked list
 * @head: linked list
 * @str: data for new node
 * Return: address of new element, or NULL if failed
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node, *tmp; /* create new node */

	if (str == NULL) /* validate input */
		return (NULL);
	if (strdup(str) == NULL) /* check if malloc errored */
		return (NULL);

	new_node = malloc(sizeof(list_t)); /* malloc for new node */
	if (new_node == NULL)
		return (NULL);

	new_node->var = strdup(str); /* set node values */
	new_node->next = NULL;

	if (*head == NULL) /* if no list nodes, set new_node to beginning */
		*head = new_node;
	else
	{
		tmp = *head;

		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}

	return (new_node);
}
