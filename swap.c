#include "monty.h"


/**
 * pint - Prints the value of the top element in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The pint function prints the value
 *						of the top element in the stack
 *					or terminates the program with an error message
 *							if the stack is empty.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		pint_error(line_number);

	printf("%d\n", (*stack)->n);
}

/**
 * pint_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 *
 * Description: The pint_error function prints an error message
 *						when attempting to pint from an empty stack,
 *								and then terminates the program with a failure status.
 */

void pint_error(int line_number)
{

	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * swap - Swaps the positions of the top two elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The swap function swaps the position
 *						of the top two elements in the stack
 *					or terminates the program with
 *						an error message if the stack is too short.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL || *stack == NULL)
		swap_error(line_number);

	if ((*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
		swap_error(line_number);
}

/**
 * swap_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 *
 * Description: The swap_error function prints an error message
 *							when the stack is too short
 *					to perform a swap operation,
 *				and then terminates the program with a failure status.
 */

void swap_error(int line_number)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
