#include "monty.h"
/**
 * get_opcode - gets function corresponding to opcode
 * @buffer: opcode
 * Return: pointer to function that gets a double pointer to
 * a stack and an int and returns void
 */
void (*get_opcode(char *buffer))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(buffer, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
