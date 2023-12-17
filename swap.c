#include "monty.h"
/**
 * swap - swaps the last 2 elements of the stack
 * @stack: double pointer to the last element of the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *antep;

	temp = (*stack)->prev;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->prev != NULL)
	{
		antep = temp->prev;
		antep->next = *stack;
		(*stack)->prev = antep;
	}
	else
	{
		(*stack)->prev = NULL;
	}
	(*stack)->next = temp;
	temp->prev = *stack;
	temp->next = NULL;
	*stack = (*stack)->next;
}
