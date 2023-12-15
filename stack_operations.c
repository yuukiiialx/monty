#include "monty.h"


/**
 * print_stack - Prints all the elements of a stack_t list
 * @h: Pointer to stack_t head
 * Return: The number of nodes
 *
 * Description: The print_stack function traverses
 *					the stack and prints the value
 * of each node, returning the total number of nodes in the stack.
 */

size_t print_stack(const stack_t *h)
{
	int i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 *
 * Description: The add_dnodeint function creates a new node
 *					with the specified value
 * and adds it at the beginning of the doubly linked list.
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head)
	{
		(*head)->prev = new_node;
		new_node->next = *head;
	}
	*head = new_node;

	return (new_node);
}

/**
 * add_stackint_end - Adds a new node at the end of a stack_t list
 * @head: Pointer to head pointer
 * @n: Integer value
 * Return: Node address or null in case of failure
 *
 * Description: The add_stackint_end function creates a new node
 *						with the specified value
 * and adds it at the end of the stack_t list.
 */

stack_t *add_stackint_end(stack_t **head, const int n)
{
	stack_t *new_node, *current;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	/*add new node in the beginning of the list*/
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;

		new_node->prev = current;
		current->next = new_node;
	}

	return (new_node);
}

/**
 * free_stack - Frees all the elements of a stack_t list
 * @head: Pointer to stack_t
 * Return: Nothing
 *
 * Description: The free_stack function frees all the nodes in the stack_t list
 * releasing the memory allocated for each node.
 */

void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head;
		head = head->next;
		if (current)
			free(current);
	}
}

/**
 * delete_top_node - Removes the top node from the stack
 * @stack: Pointer to stack_t
 *
 * Description: The delete_top_node function removes the top node from the stac
 * freeing the memory allocated for that node.
 */


void delete_top_node(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("Error: Stack is empty.\n");
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	temp->next = NULL;
	free(temp);
}
