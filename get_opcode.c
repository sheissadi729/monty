#include "monty.h"
/**
 * get_opcode - gets function corresponding to opcode
 * @buffer: opcode
 * @line: line number
 * Return: pointer to function that gets a double pointer to
 * a stack and an int and returns void
 */
void (*get_opcode(char *buffer, unsigned int line))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", division}, {NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(buffer, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line, buffer);
	exit(EXIT_FAILURE);
}
