#include "monty.h"
/**
 * free_dlist - frees a doubly linked list
 * @stack : sdouble pointer to the last node of the list
 */
void free_dlist(stack_t **stack)
{
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		temp = (*stack)->prev;
		free(*stack);
		*stack = temp;
	}
}
