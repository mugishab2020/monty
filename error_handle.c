#include "monty.h"

/**
 * _free - function to free the stack
 * @stack: input stack
 */

void _free(stack_t *stack)
{
stack_t *clean = NULL;

	clean = stack;

	if (clean != NULL)
	{
		_free(clean->next);
		free(clean);
	}

}

/**
 * clean_stack - function to free all and close files
 * @stack: Stack inputed to be freed and closed
 */

void clean_stack(stack_t **stack)
{
	stack_t *tempo = *stack;

	while (tempo)
	{
		tempo = *stack;
		*stack = (*stack)->next;
		free(tempo);
	}
	fclose(cmd.fd);
	free(cmd.line);
}
/**
 * instruction_error - Error handler for unknown instructions
 * @fd: file descriptor
 * @line: buffer
 * @stack:  stack or queue
 * @line_n: line number of the command
 * @val: instruction
 */
void instruction_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_n, val);
	fclose(fd);
	free(line);
	_free(stack);
	exit(EXIT_FAILURE);
}
