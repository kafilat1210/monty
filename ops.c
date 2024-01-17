#include "monty.h"
/**
 * kf_rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script where the opcode appears.
 */
void kf_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current;

	(void)line_number; /* Unused parameter */

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		/* Nothing to rotate if the stack is empty or has only one node */
		return;
	}

	/* Move the first element to the end of the stack */
	temp = *stack; /* Save the current top */
	current = *stack;
	while (current->next != NULL) /* Traverse to the last node */
	{
		current = current->next;
	}
	/* Re-linking */
	*stack = temp->next; /* Change top to the second node */
	temp->next->prev = NULL;
	current->next = temp; /* Append first node to the end */
	temp->prev = current;
	temp->next = NULL; /* Now the previous top is the last node */
}
/**
 * kf_rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script where the opcode appears.
 */
void kf_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
	{
		return;
	}

	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
