#include "monty.h"


/**
 * stack - Sets the stack mode
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The stack function sets the mode to STACK for LIFO behavior.
 */

void stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	my_data.mode = STACK;
}

/**
 * queue - Sets the queue mode
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The queue function sets the mode to QUEUE for FIFO behavior.
 */


void queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	my_data.mode = QUEUE;
}

