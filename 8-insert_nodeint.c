#include "shell.h"
/**
 * insert_nodeint_at_index - Inserts a newnode at the specified index
 * @head: list pointer
 * @idx: index to insert newnode
 * @str: data for new node
 * Return: Adress of new node
 */
list_t *insert_nodeint_at_index(list_t **head, unsigned int idx, char *str)
{
	list_t *newnode = malloc(sizeof(*newnode));
	list_t *node;
	unsigned int j;

	if (head == NULL)
		return (NULL);
	if (newnode == NULL)
		return (NULL);
	node = *head;
	newnode->var = str;
	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	for (j = 0; j < (idx - 1); j++)
	{
		node = node->next;
		if (node == NULL)
		{
			free(newnode);
			return (NULL);
		}
	}
	newnode->next = node->next;
	node->next = newnode;
	return (newnode);
}
