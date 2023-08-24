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
 * tokenizer - to token opcode
 */

void tokenizer(void)
{
	int i = 0;
	char *delim = " \n", *token = NULL, *copied_line = NULL;

	copied_line = malloc(sizeof(char) * arguement->line_len);
	if (copied_line == NULL)
		failed_malloc();
	strcpy(copied_line, arguement->line);
	token = strtok(copied_line, delim);
	while (token)
	{
		arguement->token_number++;
		token = strtok(NULL, delim);
	}
	arguement->token = malloc(sizeof(char *) *
			(arguement->token_number + 1));
	strcpy(copied_line, arguement->line);
	token = strtok(copied_line, delim);
	while (token)
	{
		arguement->token[i] = malloc(sizeof(char) *
			(strlen(token) + 1));
		if (arguement->token[i] == NULL)
			failed_malloc();
		strcpy(arguement->token[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	arguement->token[i] = NULL;
	free(copied_line);
}
