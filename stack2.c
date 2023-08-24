#include "monty.h"


/**
 * nop - it does nothing
 * @stack: the node list
 * @line_num: position of list
 */

void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
 * mul - adds the top two elements of the stack
 * @stack: node list
 * @line_num: position of node
 */

void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int res;
	(void) stack;

	if (arguement->head == NULL || arguement->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_all_arg();
		exit(EXIT_FAILURE);
	}

	res = arguement->head->n * arguement->head->next->n;
	temp = arguement->head;
	arguement->head = arguement->head->next;
	if (arguement->head != NULL)
		arguement->head->prev = NULL;
	free(temp);

	arguement->head->n = res;
	arguement->stack_len -= 1;
}

/**
 * sub - adds the top two elements of the stack
 * @stack: node list
 * @line_num: position of node
 */

void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int res;
	(void) stack;

	if (arguement->head == NULL || arguement->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		free_all_arg();
		exit(EXIT_FAILURE);
	}

	res = arguement->head->n - arguement->head->next->n;
	temp = arguement->head;
	arguement->head = arguement->head->next;
	if (arguement->head != NULL)
		arguement->head->prev = NULL;
	free(temp);

	arguement->head->n = res;
	arguement->stack_len -= 1;
}

/**
 * add - adds the top two elements of the stack
 * @stack: node list
 * @line_num: position of node
 */

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int res;
	(void) stack;

	if (arguement->head == NULL || arguement->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_all_arg();
		exit(EXIT_FAILURE);
	}

	res = arguement->head->n + arguement->head->next->n;
	temp = arguement->head;
	arguement->head = arguement->head->next;
	if (arguement->head != NULL)
		arguement->head->prev = NULL;
	free(temp);

	arguement->head->n = res;
	arguement->stack_len -= 1;
}
