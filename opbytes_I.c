#include "monty.h"

/**
 * kf_swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	/* Check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Swap the top two elements */
	tmp = (*stack)->next; /* Node after top */
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	if ((*stack)->next != NULL)
	{
		(*stack)->next->prev = *stack;
	}
	*stack = tmp; /* Update the top of the stack to the second node */
}
/**
 * kf_add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	/* Check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform the addition */
	top = *stack;
	second_top = (*stack)->next;
	second_top->n += top->n;

	/* Remove the top element */
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
/**
 * kf_nop - Does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* No operation */
}
/**
 * kf_sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	/* Check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform the subtraction */
	top = *stack;
	second_top = (*stack)->next;
	second_top->n -= top->n;

	/* Remove the top element */
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
/**
 * kf_div - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the opcode appears.
 */
void kf_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	/* Check if the stack contains less than two elements */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the top element is zero */
	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Perform the division */
	second_top = (*stack)->next;
	second_top->n /= top->n;

	/* Remove the top element */
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
