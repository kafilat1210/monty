#include "monty.h"
/**
 * kf_mul - Multiplies the second top element of the stack with the top ele
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	/* Check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform the multiplication */
	top = *stack;
	second_top = (*stack)->next;
	second_top->n *= top->n;

	/* Remove the top element */
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
/**
 * kf_mod - Computes the remainder of the division of the second top element
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	/* Check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the top element is zero */
	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform the modulus operation */
	second_top = (*stack)->next;
	second_top->n %= top->n;

	/* Remove the top element */
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
