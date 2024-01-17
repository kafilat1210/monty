#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 always success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		/* Split line into opcode and argument */
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		/* Execute opcode */
		if (strcmp(opcode, "push") == 0)
			kf_push(&stack, line_number, arg);
		else if (strcmp(opcode, "pall") == 0)
			kf_pall(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);

	return (0);
}
