#include "monty.h"
/**
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo;
	int a = 0;

	tempo = *stack;
	if (tempo == NULL || tempo->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		a = tempo->n;
		tempo->n = tempo->next->n;
		tempo->next->n = a;
	}
}
/**
 * pchar - function to add top two elements of the stack.
 * @stack: the stack to deal with
 * @line_number: The val holding the number of live for error prinnting
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

}
