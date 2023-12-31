#include "monty.h"

/**
 * _push - add a node to the top of the stack
 * @stack: address of the pointer to the stack
 * @line_number: line number to execute
 *
 * Description: Generates error and exits if unsuccessful
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;	/* new node */

	if (stack == NULL)
	{
		return;
	}
	if (bytecode.opcode_arg == INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Redirect to a push function for queues */
	if (bytecode.state == FIFO)
	{
		_q_push(stack, line_number);
		return;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{/* Malloc failure */
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = bytecode.opcode_arg;	/* assign values */
	new->prev = new->next = NULL;	/* Initialize pointers */

	/* Add the node at the beginning of the list */
	new->next = (*stack);
	if ((*stack) != NULL)	/* Non-empty list */
		(*stack)->prev = new;

	(*stack) = new;
}
