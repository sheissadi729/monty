#include "monty.h"
/**
 * push - pushes an int to the stack
 * @ptr: pointer to the last node of a doubly linked list
 * @num: int to add to the stack
 * Return: node created
 */
stack_t *push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	temp->n = line_number;
	temp->next = NULL;
	temp->prev = *stack;
	(*stack)->next = temp;
	return (temp);
}
