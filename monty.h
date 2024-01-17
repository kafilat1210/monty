#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void kf_push(stack_t **stack, unsigned int line_number, char *arg);
void kf_pall(stack_t **stack, unsigned int line_number);
void kf_exec_op(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number);
void kf_process_file(char *filename, stack_t **stack);
int is_number(const char *str);
void kf_pint(stack_t **stack, unsigned int line_number);
void kf_free_stack(stack_t **stack);
void kf_exec_op(char *opcode, char *arg, stack_t **stack,
		unsigned int line_number);
void kf_swap(stack_t **stack, unsigned int line_number);
void kf_pop(stack_t **stack, unsigned int line_number);
void kf_add(stack_t **stack, unsigned int line_number);
void kf_nop(stack_t **stack, unsigned int line_number);
void kf_sub(stack_t **stack, unsigned int line_number);
void kf_div(stack_t **stack, unsigned int line_number);
void kf_mul(stack_t **stack, unsigned int line_number);
void kf_mod(stack_t **stack, unsigned int line_number);
void kf_pstr(stack_t **stack, unsigned int line_number);
void kf_pchar(stack_t **stack, unsigned int line_number);
void kf_rotl(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
