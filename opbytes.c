#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * kf_push - Pushes an integer onto the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number of the Monty bytecode file
 * @arg: The string argument containing the integer to push
 */
void kf_push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int num;
	stack_t *new_node;

	if (arg == NULL || (*arg == '\0' || (*arg == '-' && !isdigit(*(arg + 1)))))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * kf_pall - Prints all values on the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number of the Monty bytecode file
 */
void kf_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
