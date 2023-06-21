#include "monty.h"
/**
 * usage_error - prints an usage error message
 * Return: FAILURE
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);

}

/**
 *open_error - prints an open file error message
 *@file: file
 * Return: FAILURE
 */
void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);

	exit(EXIT_FAILURE);

}
/**
 * pushing_error - handles a push error
 * @fd: file desciptor
 * @line: buffer
 * @stack:  stack or queue
 * @line_number: line number of the command
 */
void pushing_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(line);
	_free(stack);
	exit(EXIT_FAILURE);
}

