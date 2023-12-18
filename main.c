#include "monty.h"
/**
 * main - opens a file and gets the instruction
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	char *opc, *token, buffer[300];
	unsigned int line = 0, num;
	void (*p)(stack_t **, unsigned int);
	stack_t *last_node = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 300, file) != NULL)
	{
		opc = strtok(buffer, " $\t\n");
		token = strtok(NULL, " \t\n");
		line++;
		if (*opc == '#')
			nop(&last_node, line)
		if (token != NULL)
			num = atoi(token);
		if (opc == NULL)
			continue;
		p = get_opcode(opc, line);
		if (p != NULL)
		{
			if (strcmp(opc, "push") == 0)
				p(&last_node, num);
			else
				p(&last_node, line);
		}
	}
	fclose(file);
	free_dlist(&last_node);
	return (0);
}
