include "monty.h"

/**
 * main - Entry point of our program
 * @ac: number of arguments
 * @av: vector of agruments
 * Return: Nothing
 */
int main(int ac, int** av)
{
	stack_t *node;
	FILE *file;
	unsigned char instruction;
	unsigned int n;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	
	file = fopen(av[1], "r");
	if (file = NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fread(&instruction, 1, 1, file) == 1)
	{
		if (instruction > 0xFF)
		{
			printf("%s: unknown instruction \n", ftell(file) - 1);
			exit (EXIT_FAILURE);
		}
		switch (instruction)
		{
			case "push":
				{
					fread(&n, 1, 1, file);
					push(&node, n);
					break;
				}
			case "pall":
				{
					pall(&node);
					break;
				}
			default:
				break;
		}
	}
	fclose(file);
	return (0);
}
