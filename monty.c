#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
#include <sys/types.h>

/**
 * kf_process_file - Processes a file
 * @filename: Name of the file
 * @stack: Pointer to stack
 * Return: Nothing
 */
void kf_process_file(char *filename, stack_t **stack)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode, *arg;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n\r");
		arg = strtok(NULL, " \t\n\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		kf_exec_op(opcode, arg, stack, line_number);
	}

	free(line);
	kf_free_stack(stack);
	fclose(file);
}

/**
 * kf_exec_op - Executes an opcode
 * @opcode: Opcode to execute
 * @arg: Argument for the opcode
 * @stack: Pointer to stack
 * @line_number: Line number
 * Return: Nothing
 */
void kf_exec_op(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		kf_push(stack, line_number, arg);
	else if (strcmp(opcode, "pall") == 0)
		kf_pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		kf_pint(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	kf_process_file(argv[1], &stack);

	return (EXIT_SUCCESS);
}
/**
 * kf_free_stack - Frees a stack.
 * @stack: A pointer to the top of the stack.
 */
void kf_free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
