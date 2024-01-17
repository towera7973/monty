#include "monty.h"
/**
 * _pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void _pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
