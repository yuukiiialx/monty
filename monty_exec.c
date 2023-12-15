#include "monty.h"


/**
 * execute_file - Reads and executes operations from a file
 * @file_name: Name of the file containing the operations
 *
 * Return: 0 on success, -1 on failure
 *
 * Description: The execute_file function opens the specified file, reads and
 * executes each line of operation until the end of the file, and then closes
 * the file and frees the memory.
 */

int execute_file(char *file_name)
{
	FILE *file;
	char *line = NULL;
	size_t line_length = 0;
	ssize_t read;

	file = fopen(file_name, "r");

	if (file == NULL)
		open_file_error(file_name);
	my_data.file = file;
	while ((read = getline(&line, &line_length, file)) != -1)
	{
		my_data.line_number++;
		my_data.line = line;
		if (is_empty_line(my_data.line) == 1)
			execute_line(my_data.line, my_data.line_number);
	}
	free_stack(my_data.stack);
	fclose(file);
	free(line);
	return (0);
}

/**
 * execute_line - Executes a single line of operation
 * @line: Line of operation
 * @line_number: Line number of the current operation
 *
 * Description: The execute_line function parses the input line, identifies the
 * corresponding operation, and executes the operation accordingly.
 */

void execute_line(char *line, int line_number)
{
	int i;
	int is_instruction = -1;
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"add", add},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
	};
	my_data.arg1 = strtok(line, " \n");
	my_data.arg2 = strtok(NULL, " \n");
	if (my_data.arg1[0] == '#')
	{
		nop(&my_data.stack, line_number);
		return;
	}
	for (i = 0; i < INSTRUCTIONS_COUNT; i++)
		if (strcmp(my_data.arg1, instructions[i].opcode) == 0)
		{

			is_instruction = i;
			break;
		}
	if (is_instruction != -1)
		instructions[i].f(&my_data.stack, line_number);
	else
		invalid_instruction_error(line_number, my_data.arg1);
}

/**
 * is_empty_line - Checks if a line is empty
 * @line: Line to check
 *
 * Return: 1 if the line is empty, 0 otherwise
 *
 * Description: The is_empty_line function checks if a line contains characters
 * before the end of line character, and returns 1
 *			if the line is empty, and 0 otherwise.
 */

int is_empty_line(char *line)
{
	int i;
	int length = strlen(line);

	if (length > 0)
	{
		if (line[length - 1] == '\n')
		{
			for (i = 0; i < length - 1; i++)
			{
				if (line[i] != ' ')
					return (1);
			}
			return (0);
		}
	}

	return (0);
}
