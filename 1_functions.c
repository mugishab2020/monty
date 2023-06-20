#include "monty.h"
/**
 * pop - function emoves the top element of the stack.
 * @stack: the stack to be pooped
 * @line_number:  identify the line number in case of an error.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{

		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		return;
	}
	stack_t *poping = *stack;
	*stack = poping->prev;

	if (*stack != NULL)
		(*stack)->next = NULL;
	printf("Popped element: %d\n", poping->n);
	free(poping);
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: the stack to be operated
 * @line_number: the variable to oled error number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	new = *stack;
	int tempo = 0;

	if (new == NULL || new->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tempo = new->n;
	new->n = new->next->n;
	new->next->n = tempo;
}
/**
 * add - adds the top two elements of the stack.
 * @stack: stack to be operated
 * @line_number: variable to hold the number wwoth error
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next += (*stack)->next->n;
	pop(stack, line_number);
}
/**
 * npop - function for stoping pop function
 * @stack: the stack to be operated
 * @line_number: the var to hold the error number
 */
void npop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
