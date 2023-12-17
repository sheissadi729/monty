#include "monty.h"
/**
 * main - opens a file and gets the instruction
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	unsigned int line = 0;
	char *filename, *opc, *token, buffer[300];
	FILE *file;
	unsigned int num;
	void (*p)(stack_t **, unsigned int);
	stack_t *last_node = NULL;

	(void)line;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 300, file) != NULL)
	{
		opc = strtok(buffer, " $\t\n");
		token = strtok(NULL, " \t\n");
		if (token != NULL)
			num = atoi(token);
		if (opc == NULL)
			continue;
		line++;
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
