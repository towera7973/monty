#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct global_s - this is a data structure with variables -> args, file, line content,
 * it has been declared as global by command extern ,,glob is a pointer pointing to it
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
	int A;
} global_t;

extern global_t glob;

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
void execute_file(stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void add_queue(stack_t **stack, int n);
void rotl(stack_t **stack, unsigned int line_count);
/* Stack helper functions */
stack_t *add_Newnode(stack_t **stack, const int n);
int is_number(char *str);
void free_stack(stack_t *stack);

#endif /* monty.h */
