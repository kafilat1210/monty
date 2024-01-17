#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
/**
 * kf_push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * @arg: The string argument containing the integer to push
 *
 * Return: nothing
 */
void kf_push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int num;

	if (!is_number(arg))
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
 * kf_pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void kf_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * is_number - Checks if string is a number
 * @str: String to check
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(const char *str)
{
	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
/**
 * kf_pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number.
 *
 * Return: nothing.
 */
void kf_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
