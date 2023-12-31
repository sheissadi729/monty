#include "monty.h"
/**
 * pint - prints value at the top of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
