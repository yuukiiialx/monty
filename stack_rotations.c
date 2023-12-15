#include "monty.h"


/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The rotl function rotates the stack to the top,
 *					moving the top element to the bottom.
 */


void rotl(stack_t **stack, unsigned int line_number)
{
	int top = 0;
	stack_t *c = NULL;

	UNUSED(line_number);
	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		top = (*stack)->n;
		c = *stack;
		while (c->next)
		{
			c->n = c->next->n;
			c = c->next;
		}
		c->n = top;
	}
}

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 *
 * Description: The rotr function rotates the stack to the bottom,
 *						moving the bottom element to the top.
 */


void rotr(stack_t **stack, unsigned int line_number)
{
	int last = 0;
	stack_t *c = NULL;

	UNUSED(line_number);

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		c = *stack;

		while (c->next != NULL)
		{
			last = c->n;
			c = c->next;
		}

		last = c->n;

		while (c->prev != NULL)
		{
			c->n = c->prev->n;
			c = c->prev;
		}

		(*stack)->n = last;
	}
}
