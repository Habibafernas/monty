#include "monty.h"
#define _GNU_SOURCE



/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector
*
*/
int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0}
	char *content;
	FILE *file;
	size_t s = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &s, file);
		bus.content = content;
		counter++;

		if (read_line > 0)
			execute(content, &stack, counter, file);

		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
