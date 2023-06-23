#include "monty.h"
/**
 * main - This is the main functiono f our program
 * @ac: number of arguments
 * @av: vector of agruments
 * Return: Nothing
 */
int main(int ac, char** av)
{

	if (ac != 2)
	{
		usage_error();
	}
	else
	{
		execute(av[1]);
	}

	return (EXIT_SUCCESS);

}
