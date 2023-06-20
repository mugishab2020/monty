#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: the stack structure to push in
 * @line_number: the variable to be pushed
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new_node;
}
/**
 * pall - prints all the values on the stack from the top of the stack.
 * @stack: the structure of the stack to be printed
 */
void pall(stack_t *stack)
{
	stack_t *position = *stack;

	while (position != NULL)
	{
		printf("%d\n", position->n);
		position = position->next;
	}
}
/**
 * pint - Prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number we are on
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "Error at line %u: Stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
