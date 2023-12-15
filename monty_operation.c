#include "monty.h"
/**
 * sub - Subtracts the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 *
 * Description: The sub function subtracts the top element of the stack from
 * the second element and stores the result in the second element. It then
 * removes the top element from the stack.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		sub_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		delete_top_node(stack);
	}
	else
		sub_error(line_number);
}

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 *
 * Description:The add function adds the top element of the stack to the second
 * element and stores the result in the second element. It then removes the top
 * element from the stack.
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		add_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		delete_top_node(stack);
	}
	else
		add_error(line_number);
}

/**
 * mod - Computes the modulo of the second element
 *			by the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 *
 * Description: The mod function computes the modulo
 *			of the second element of the
 * stack by the top element, stores the result in the second element
 *			and removes
 * the top element from the stack. If the top element is 0,
 *					it prints an error message
 * and exits with a failure status.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		mod_error(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			div_by_zero_error(line_number);
		(*stack)->next->n %= (*stack)->n;
		delete_top_node(stack);
	}
	else
		mod_error(line_number);
}
/**
 * mod_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 *
 * Description: The mod_error function prints an error message when the stack
 *		is too short
 *				to perform a mod operation, and then
 *			terminates the program with a failure status.
 */
void mod_error(int line_number)
{

	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * add_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 *
 * Description: The add_error function prints an error message when the stack
 *			is too short
 *		to perform an add operation, and then
 *			terminates the program with a failure status.
 */

void add_error(int line_number)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

