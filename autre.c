#include "monty.h"

/**
 * _num - check if it is a number
 * @str: character to be checked
 * Return: 1 (true) or 0
 */

int _num(char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);
	return ((*str != '\0' && *endptr == '\0') ? 1 : 0);
}

/**
 * check_arg - To check if arg is 2
 * @argc: number of arguments
 */

void check_arg(int argc)
{
	if (argc == 2)
		return;
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
