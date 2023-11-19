#include "monty.h"

/**
* pall - print everything in stack
* @head: pointer to pointer of first node
* @count: line counter (not used)
*
* Return: none
*/

void pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
