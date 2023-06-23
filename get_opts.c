#include"monty.h"

int value;
/**
 * get_operation - function that returns the operation to be made
 * @stack: This is the stack that we are dealing with
 * @arg: ppointer that will pointing to the operation
 * @val: the value of the operation
 * @line_number: the line number
 * Return: 0 when it seccedd, 1 if not a digit ro -1 on error
 */

int get_operation(stack_t **stack, char *arg, char *val, int line_number)
{
	int a = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", npop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (op[a].opcode)
	{
		if (!strcmp(arg, op[a].opcode))
		{
			 if (!strcmp(arg, "push"))
			{
				if (_isdigit(val) == 1)
					value = atoi(val);
				else
					return (1);
			}

			op[a].f(stack, (unsigned int)line_number);
			break;
		}
		a++;
	}
	if (!op[a].opcode)
		return (-1);

	return (0);
}
