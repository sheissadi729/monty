#include "monty.h"
/**
 * add - adds the last 2 elements of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int sum;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (temp->n);
	pop(stack, line_number);
	pop(stack, line_number);
	push(stack, sum);
}
