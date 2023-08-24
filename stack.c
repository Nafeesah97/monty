#include "monty.h"

/**
 * push - push n integer into stack
 * @stack: stack
 * @line_num: line number
 */

void push(stack_t **stack, unsigned int line_num)
{

	if (arguement->token_number <= 1 || _num(arguement->token[1]) == 0)
	{
		free_arg();
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		failed_malloc();
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->n = (int) atoi(arguement->token[1]);

	if (arguement->head != NULL)
	{
		(*stack)->next = arguement->head;
		arguement->head->prev = *stack;
	}
	arguement->head = *stack;
	arguement->stack_len += 1;
}

/**
 * pop - delete the last node
 * @stack: node list
 * @line_num: position of line
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) stack;

	if (arguement->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_num);
		free_all_arg();
		exit(EXIT_FAILURE);
	}
	temp = arguement->head;
	arguement->head = arguement->head->next;

	if (arguement->head != NULL)
		arguement->head->prev = NULL;
	free(temp);
	arguement->stack_len -= 1;
}

/**
 * pall - print all data
 * @line_num: position of line
 * @stack: node list
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void) stack;
	(void) line_num;

	if (arguement->head == NULL)
		return;

	current = arguement->head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
