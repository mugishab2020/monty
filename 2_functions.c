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
