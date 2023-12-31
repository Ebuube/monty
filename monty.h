#ifndef __MONTY_H__
#define __MONTY_H__


/* Header files */

#ifndef _GNU_SOURCE
#define _GNU_SOURCE	/* To get access to the 'getline()' function */
#include <stdio.h>
#endif	/* _GNU_SOURCE */
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

/* Definition of Macros */

#define UNUSED __attribute__((unused))


/* Data structures */

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
 * @opcode: A character string to represent the opcode
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

/**
 * enum state_s - describes the state of the machine.
 * Can either be in the 'stack' state or 'queue' state
 * @LIFO: Last In, First Out state that is 'stack'
 * @FIFO: First In, First Out state that is 'queue'
 */
enum state_s
{
	LIFO,
	FIFO
};

/**
 * struct bytecode_s - properties of a line in a bytecode file
 * @opcode: a character string representing the opcode to run
 * @opcode_arg: a variable specifying the argument to the opcode
 * @state: The operating state can be either 'LIFO' or 'FIFO' (enumerators)
 *
 * Description: bytecode file and the properties of a line in it;
 */
typedef struct bytecode_s
{
	char *opcode;
	int opcode_arg;
	enum state_s state;
} bytecode_t;


/* new types definition */

/**
 * opcode_func - Typedef for pointer to an opcode function
 *
 * Description: stack_t ** is type for stack,
 * unsigned int is for line number
 */
typedef void opcode_func(stack_t **, unsigned int);


/* Functions */

FILE *read_file(stack_t **stack, FILE *fp_stream);
void free_stack(stack_t **head);
size_t parse_line(char **arr_buffer, size_t buf_size, char *delim,
		char *cp_line);
int execute(stack_t **stack, unsigned int line_number);
opcode_func *get_opcode_func(void);
int _strtoi(char *str);
size_t _intlen(int num);


/* Opcodes */

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
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _q_push(stack_t **stack, unsigned int line_number);


/* Global variables */

extern bytecode_t bytecode;

/* definition of global variable */
bytecode_t bytecode;


#endif	/* __MONTY_H__ */
