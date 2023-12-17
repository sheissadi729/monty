#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack != NULL)
	{
		*stack = temp->prev;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
