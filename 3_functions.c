#include "monty.h"
/**
 * divide -  funcctio to devide and swap second top element of the stack
 * @stack: the stack to deal with
 * @line_number: hold the current number for reference when error happenes
 */
void divide(stack_t **stack, unsigned int line_number)
{

	stack_t *my_value = NULL;
	int quotient = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

		if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	my_value = (*stack)->next;
	quotient= my_value->n;
	quotient /= (*stack)->n;
	pop(stack, line_number);
	my_value->n = quotient;
}
/**
 * mul - function that make the multiplication
 * @stack: The stack to be dealing with
 * @line_number: hoold the current line for reference when error happens
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *my_value = NULL;
	int product = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	my_value = (*stack)->next;
	product = my_value->n;
	product *= (*stack)->n;
	pop(stack, line_number);
	my_value->n = product;
}

/**
 * mod - function make the modulus of the input number
 * @stack: the stack to be dealing with
 * @line_number: val that hold the current number for pring error if happened
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *valiable = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	valiable = (*stack)->next;
	sum = valiable->n;
	sum %= (*stack)->n;
	pop(stack, line_number);
	valiable->n = sum;
}
