#include "monty.h"
/**
 * division - divides 2nd element by top element of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int quotient;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (temp->n) / (*stack)->n;
	pop(stack, line_number);
	pop(stack, line_number);
	push(stack, quotient);
}
