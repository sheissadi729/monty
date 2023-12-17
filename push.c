#include "monty.h"
/**
 * push - pushes an int to the stack
 * @stack: double pointer to the last node of a doubly linked list
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	temp->n = line_number;
	temp->next = NULL;
	if (*stack == NULL)
	{
		temp->prev = NULL;
		*stack = temp;
	}
	else
	{
		temp->prev = *stack;
		(*stack)->next = temp;
		*stack = temp;
	}
}
