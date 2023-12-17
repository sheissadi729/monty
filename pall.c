#include "monty.h"
/**
 * pall - prints the values on the stack starting from the top of the stack
 * @stack: double pointer to the last node of the stack
 * @line_number: line number of the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack != NULL)
	{
		temp = *stack;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
		free_dlist(stack);
	}
}
