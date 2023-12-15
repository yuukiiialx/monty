#include "monty.h"

/**
* sub_error - Prints an error message and terminates the program
*				if the stack is too short for the "sub" operation
* @line_number: Line number of the current operation
* Return: Nothing
*
* Description: The sub_error function prints an error message when the stack
*			is too short to perform a subtraction operation,
*						and then exits with a failure status.
*/

void sub_error(int line_number)
{

fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
free_everything();
exit(EXIT_FAILURE);
}

/**
 * is_number - Checks if a string represents a valid integer
 * @num: The string to check
 * Return: 1 if the string is a valid integer, 0 otherwise
 *
 * Description: The is_number function checks if a string
 *		represents a valid integer and returns 1
 *			if it is a valid integer, and 0 otherwise.
*/

int is_number(char *num)
{
int i = 0;

if (num[i] == '-')
	i++;

while (num[i])
{
	if (!(num[i] >= '0' && num[i] <= '9'))
		return (0);
	i++;
}

return (1);
}
