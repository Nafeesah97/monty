#include "monty.h"

/**
 * initialize_arg - initializes arguments
 */

void initialize_arg(void)
{
	arguement = malloc(sizeof(args_t));
	if (arguement == NULL)
		failed_malloc();

	arguement->instruct = malloc(sizeof(instruction_t));
	if (arguement->instruct == NULL)
		failed_malloc();
	arguement->stream = NULL;
	arguement->line = NULL;
	arguement->token_number = 0;
	arguement->l_num = 0;
	arguement->line_len = 0;
	arguement->head = NULL;
	arguement->stack_len = 0;
}

/**
 * which_instruct - To know which instruction to carry out
 */

void which_instruct(void)
{
	int i = 0;
	instruction_t instructions[] = {{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop}, {"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &sub}, {"mul", &mul}
	};

	if (arguement->token_number == 0)
		return;
	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arguement->token[0]) == 0)
		{
			arguement->instruct->opcode = instructions[i].opcode;
			arguement->instruct->f = instructions[i].f;
			return;
		}
	}
	invalid_ins();
}

/**
 * invalid_ins - invalid instruction was given
 */

void invalid_ins(void)
{
	fprintf(stderr, "L%d: unknown instruction %s", arguement->l_num,
			arguement->token[0]);
	stream_closed();
	free_token();
	free_arg();
	exit(EXIT_FAILURE);
}

/**
 * action - to run instruction
 */

void action(stack_t **stack)
{
	if (arguement->token_number == 0)
		return;
	arguement->instruct->f(stack, arguement->l_num);
}

/**
 * tokenizer - to token opcode
 */

void tokenizer(void)
{
	char *delim = " \n";
	char *token = NULL, *copied_line = NULL;

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
		arguement->token_number = 0;
		arguement->token[arguement->token_number] = malloc(sizeof(char)
				* (strlen(token) + 1));
		if (arguement->token[arguement->token_number] == NULL)
			failed_malloc();
		strcpy(arguement->token[arguement->token_number], token);
		token = strtok(NULL, delim);
		arguement->token_number++;
	}
	arguement->token[arguement->token_number] = NULL;
	free(copied_line);
}

