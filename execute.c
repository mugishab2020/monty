#include "monty.h"
#include <stdio.h>

cmd_t cmd = {NULL, NULL};

/**
 *execute -functionn that reads the file and executes the monty byte
 *@argv: argument vector
 */

void execute(char *argv)
{
	int c_line = 0, r = 0;
	size_t bufsize = 0;
	char *token = NULL, *val = NULL;
	stack_t *stack = NULL;

	cmd.fd = fopen(argv, "r");
	if (cmd.fd)
	{
		while (getline(&cmd.line, &bufsize, cmd.fd) != -1)
		{
			c_line++;
			token = strtok(cmd.line, " \n\t\r");
			if (token == NULL)
			{
				free(token);
				continue;
			}
			else if (*token == '#')
				continue;
			val = strtok(NULL, " \n\t\r");
			r = get_operation(&stack, token, val, c_line);
			if (r == 1)
				pushing_error(cmd.fd, cmd.line, stack, c_line);
			else if (r == -1)
				instruction_error(cmd.fd, cmd.line, stack, token, c_line);
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
