#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"

args_t *arguement = NULL;

/**
 * OB
 * main - main function
 * @argc: number of arguements
 * @argv: arguements
 * Return: 1 or 0
 */

int main(int argc, char **argv)
{
	size_t n;

	n = 0;
	check_arg(argc);
	initialize_arg();
	open_file(argv[1]);

	while (getline(&arguement->line, &n, arguement->stream) != -1)
	{
		arguement->l_num++;
		arguement->line_len = strlen(arguement->line);
		tokenizer();
		which_instruct();
		action();
		free_token();
	}
	stream_closed();
	free_arg();
	fclose(arguement->stream);

	return (0);
}
