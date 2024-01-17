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
/**
 * kf_pchar - Prints the char at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script.
 */
void kf_pchar(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)-> n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
/**
 * kf_pstr - Prints the string starting at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script.
 */
void kf_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL && temp->n != 0 && (temp->n >= 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
