#include "monty.h"

/**
 * usage_error - Prints an error message for incorrect program usage
 *
 * Description: The usage_error function prints an error message when the
 * monty program is not used with the correct file argument, and then exits wit
 * a failure status.
 */

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_file_error - Prints an error message for file opening failure
 * @file_name: Name of the file that failed to open
 *
 * Description: The open_file_error function prints an error message when
 * the specified file fails to open, and then exits with a failure status.
 */
void open_file_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction_error - Prints an error message for unrecognized opcode
 * @line_number: Line number of the current operation
 * @opcode_instruction: Pointer to the unrecognized opcode
 *
 * Description: The invalid_instruction_error function prints an error message
 * when an unrecognized opcode is encountered
 * and then exits with faliure status
 */

void invalid_instruction_error(int line_number, char *opcode_instruction)
{

	fprintf(stderr, "L%d: unknown instruction %s\n",
							line_number, opcode_instruction);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints an error message for memory allocation failure
 *
 * Description: The malloc_error function prints an error message when a
 * memory allocation fails, and then exits with a failure status.
 */

void malloc_error(void)
{
	free_everything();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
