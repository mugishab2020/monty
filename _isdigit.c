#include "monty.h"
/**
 * _isdigit - checks if it is a digit
 * Return: 0 for not digit and 1 for digit
 * @c: Value depending on the outcome
 **/
int _isdigit(char *c)
{
	char *tempo = c;

	if (c == NULL)
		return (0);
	if (*tempo == '-')
		tempo++;

	for (; *tempo != '\0'; tempo++)
	{
		if ((*tempo < '0' || *tempo > '9'))
		{
			return (0);
		}
	}
	return (1);
}
