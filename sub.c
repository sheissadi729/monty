#include "monty.h"
/**
 * sub - sustract top element from second element of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int diff;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (temp->n) - (*stack)->n;
	pop(stack, line_number);
	pop(stack, line_number);
	push(stack, diff);
}
