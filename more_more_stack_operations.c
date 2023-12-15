#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The pall function prints all the elements in the stack
 *					by calling the print_stack function.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The push function pushes an element onto the stack
 *			based on the specified mode (STACK or QUEUE), and if the argument
 *				is not a valid integer,
 *					it prints an error message and terminates the program.
 */

void push(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (my_data.arg2)
	{
		if (is_number(my_data.arg2))
		{
			num = atoi(my_data.arg2);
			if (my_data.mode == STACK)
				add_dnodeint(stack, num);
			else
				add_stackint_end(stack, num);
		}
		else
			push_error(line_number);

	}
	else
		push_error(line_number);
}

/**
 * push_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 *
 * Description: The push_error function prints an error message
 *									when the push operation
 *							is not used with a valid integer argument
 *								and then terminates the program with a failure status.
 */

void push_error(int line_number)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * free_everything - Frees memory and closes the file
 *
 * Description: The free_everything function frees memory associated
 *						with the stack and line, and closes the file.
 */

void free_everything(void)
{
	free_stack(my_data.stack);
	fclose(my_data.file);
	free(my_data.line);
}
