#include "monty.h"
/**
 * get_opcode - gets function corresponding to opcode
 * 
 * Return: pointer to function that does the instruction or NULL
 */
void (*get_opcode(char *buffer))(stack_t, int)
{
	int i = 0;
	instruction_t instructions[] =
	{
		{"push", push}, {NULL, NULL}
	};

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(buffer, instructions[i].opcode) == 0)
		{
			call++;
			return(instructions[i].f);
		}
		i++;
	}
	return (NULL);
}
