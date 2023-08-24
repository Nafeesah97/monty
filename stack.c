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

/**
 * pint - prints the value at the top of the stack
 * @stack: node
 * @line_num: position of node
 */

void pint(stack_t **stack, unsigned int line_num)
{
	(void) stack;

	if (arguement->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free_all_arg();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguement->head->n);
}

/**
 * swap - swaps the top two elemeAOAnts of the stack
 * @stack: node list
 * @line_num: position of node
 */

void swap(stack_t **stack, unsigned int line_num)
{
	int temp;
	(void) stack;

	if (arguement->head == NULL || arguement->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_num);
		free_all_arg();
                exit(EXIT_FAILURE);
        }
	temp = arguement->head->n;
	arguement->head->n =  arguement->head->next->n;
	arguement->head->next->n = temp;
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
 * nop - it does nothing
 * @stack: the node list
 * @line_num: position of list
 */

void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
