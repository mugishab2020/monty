#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 *execute - reads the file and executes the monty byte
 *@argv: argument vector
 */

void execute(char *argv)
{
	int ln = 0, r = 0;
	size_t buf_size = 0;
	char *token = NULL, *temp = NULL;
	stack_t *stack = NULL;

	cmd.fd = fopen(argv, "r");
	if (cmd.fd)
	{
		while (getline(&cmd.line, &buf_size, cmd.fd) != -1)
		{
			ln++;
			token = strtok(cmd.line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
				continue;
			temp = strtok(NULL, " \n\t\r");
			r = get_operation(&stack, token, temp, ln);
			if (r == 1) /* get_opt return 1 when the value is not digit */
				pushing_error(cmd.fd, cmd.line, stack, ln); /** print push error*/
			else if (r == -1) /* get_opt return -1 if not the instruction */
				instruction_error(cmd.fd, cmd.line, stack, token, ln);
					/*print instruction error*/
		}
		free(cmd.line);
		_free(stack);
		fclose(cmd.fd);
	}
	else
	{

		open_error(argv);

	}
}
