#include "monty.h"

/**
 * check_arg - To check if arg is 2
 */

void check_arg(int argc)
{
	if (argc == 2)
		return;
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * failed_malloc - failed to allocate memory
 */

void failed_malloc(void)
{
	fprintf(stderr, "Error: malloc failed");
	free_arg();
	exit(EXIT_FAILURE);

}

/**
 * free_arg -  free space allocated to arguement
 */

void free_arg(void)
{
	if (arguement == NULL)
		return;

	if (arguement->instruct)
	{
		free(arguement->instruct);
		arguement->instruct = NULL;
	}
	free_head();
	if (arguement->line)
	{
		free(arguement->line);
		arguement->line = NULL;
	}

	free(arguement);
}

/**
 * free_head - free the stak head
 */

void free_head(void)
{
	if (arguement->head)
		free_stack(arguement->head);
	arguement->head = NULL;
}

/**
 * free_stack - to free the stack
 * @head: the node list
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_stack(head->next);
	free(head);
}

/**
 * free_all_arg - to free all arguements
 */

void free_all_arg(void)
{
	stream_closed();
	free_token();
	if (arguement != NULL)
	{
		free_arg();
		arguement = NULL;
	}
}


/**
 * _num - check if it is a number
 * @str: character to be checked
 * Return: 1 (true) or 0
 */

int _num(char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);
	return (*str != '\0' && *endptr == '\0') ? 1 : 0;
}

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
 * open_file - opens the file
 * @filename: the file to be opened
 */

void open_file(char *filename)
{
	FILE *stream;

	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		open_failed(filename);
	}
	arguement->stream = stream;
}

/**
 * open_failed - failed to open file
 * @filename: file
 */

void open_failed(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free_arg();
	exit(EXIT_FAILURE);
}

/**
 * tokenizer - to token opcode
 */

void tokenizer(void)
{
	int i = 0;
	char *delim = " \t\n", *token = NULL, *copied_line = NULL;

	copied_line = strdup(arguement->line);
	if (copied_line == NULL)
		failed_malloc();

	arguement->token_number = 0;
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
	while (token != NULL)
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

/**
 * which_instruct - To know which instruction to carry out
 */

void which_instruct(void)
{
	unsigned int i = 0;
	instruction_t instructions[] = {{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop}, {"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &sub}, {"mul", &mul}, {"div", &_div},
		{"mod", &mod}, {"pchar", &pchar}, {"pstr", &pstr} {NULL, NULL}
	};

	if (arguement->token_number == 0 || arguement->token == NULL)
		return;

	if (arguement->token[0][0] == '#')
	{
		arguement->instruct->opcode = "nop";
		arguement->instruct->f = nop;
		return;
	}

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
	fprintf(stderr, "L%d: unknown instruction %s\n", arguement->l_num,
			arguement->token[0]);
	stream_closed();
	free_token();
	free_arg();
	exit(EXIT_FAILURE);
}

/**
 * stream_closed - closes stream or file
 */

void stream_closed(void)
{
	if (arguement->stream != NULL)
	{
		fclose(arguement->stream);
		arguement->stream = NULL;
	}
}

/**
 * free_token - to free tokens
 */

void free_token(void)
{
	int i = 0;

	if (arguement->token == NULL)
		return;

	while (arguement->token[i] != NULL)
	{
		free(arguement->token[i]);
		i++;
	}
	free(arguement->token);
	arguement->token = NULL;
}

/**
 * action - to run instruction
 */

void action(void)
{
	stack_t *stack = NULL;

	if (arguement->token_number == 0)
		return;
	arguement->instruct->f(&stack, arguement->l_num);
}

