#include "monty.h"

/**
 * _div - Divides the second element by the top element of the stac
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 *
 * Description: The _div function divides the second element of the stack by th
 * top element, stores the result in the second element,
 *						and removes the top element
 * from the stack. If the top element is 0, it prints an error message and exit
 * with a failure status.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		div_error(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			div_by_zero_error(line_number);
		(*stack)->next->n /= (*stack)->n;
		delete_top_node(stack);
	}
	else
		div_error(line_number);

}

/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 *
 * Description: The mul function multiplies the top element of the stack with
 * second element and stores the result in the second element. It then removes
 * top element from the stack.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		mul_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		delete_top_node(stack);
	}
	else
		mul_error(line_number);

}

/**
 * mul_error - Prints an error message for multiplication operation
 * @line_number: Line number of the current operation
 *
 * Description: The mul_error function prints an error message when the stack
 * is too short to perform a multiplication operation,
 *				and then exits with a failure status.
 */

void mul_error(int line_number)
{

	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * div_error - Prints an error message for division operation
 * @line_number: Line number of the current operation
 *
 * Description: The div_error function prints an error message when the stack
 * is too short to perform a division operation,
 *						and then exits with a failure status.
 */

void div_error(int line_number)
{

	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * div_by_zero_error - Prints an error message for division by zero
 * @line_number: Line number of the current operation
 *
 * Description: The div_by_zero_error function prints an error message when a
 * division by zero is attempted, and then exits with a failure status.
 */

void div_by_zero_error(int line_number)
{

	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
