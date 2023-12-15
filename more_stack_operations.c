#include "monty.h"


/**
 * pop - Removes the top element from the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 * Return: Nothing
 *
 * Description: The pop function removes the top element from the stack,
 *						and if the stack is empty,
 *							it prints an error message and terminates the program.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		empty_stack_error(line_number);

	delete_top_node(stack);
}

/**
 * nop - Does nothing
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 * Return: Nothing
 *
 * Description: The nop function does nothing
 *			as it is a no operation (NOP) command.
*/

void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
 * empty_stack_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 *
 * Description: The empty_stack_error function prints an error message
 *						when an attempt is made to pop from an empty stack,
 *								and then exits with a failure status.
 */


void empty_stack_error(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
