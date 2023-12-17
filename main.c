#include "monty.h"
/**
 * main - opens a file and gets the instruction
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	char *filename, *opc;
	FILE *file;
	char buffer[300];
	unsigned int num;
	void (*p)(stack_t **, unsigned int);
	stack_t *last_node = NULL;
	char *token;

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
		opc = strtok(buffer, " $\t");
		token = strtok(NULL, " \t");
		if (token != NULL)
			num = atoi(token);
		p = get_opcode(opc);
		if (p != NULL)
		{
			if (last_node != NULL)
			{
				while (last_node->next != NULL)
					last_node = last_node->next;
			}
			p(&last_node, num);
		}
	}
	fclose(file);
	return (0);
}
