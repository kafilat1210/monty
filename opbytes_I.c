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

