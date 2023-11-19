#include "monty.h"

/**
* addnode - add node to top of stack
* @head: first node
* @n: new value
*
*/

void addnode(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new;

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
