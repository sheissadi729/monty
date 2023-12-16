#include "monty.h"
/**
 *
 */
int main(int argc, char **argv)
{
	char *filename, *opc;
	FILE *file;
	int size = 300, call = 0;
	char buffer[size];
	unsigned int num;
	stack_t *p(stack_t **, unsigned int);
	stack_t *stack, *temp;

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
	while (fgets(buffer, size, file) != NULL)
	{
		opc = strtok(buffer, " \t");
		num = atoi(strtok(NULL, " \t"));
		p = get_opcode(opc);
		if (p != NULL)
		{
			if (call == 1)
			{
				stack = NULL;
				p(&stack, num);
			}
			else
			{
				while (temp->next != NULL)
					temp = temp->next;
				p(&temp, num);
			}
		}
	}
	fclose(file);
}
