#include "monty.h"
int value;

/**
 * createNode - function fot creating a new node
 * @n: the value of the node
 * Return: new node
 */

stack_t *createNode(int n)
{
	stack_t *new = NULL;
	
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
/**
 * push - pushes an element to the stack
 * @stack: the stack structure to push in
 * @line_number: the variable to be pushed
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = createNode(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;

}
/**
 * pall - prints all the values on the stack from the top of the stack.
 * @stack: the structure of the stack to be printed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *position = NULL;
	(void)line_number;

	position = *stack;

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
