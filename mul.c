#include "monty.h"
/**
 * mul - multiplies top element with second element of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int product;

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
	product = (temp->n) * (*stack)->n;
	pop(stack, line_number);
	pop(stack, line_number);
	push(stack, product);
}
