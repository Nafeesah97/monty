#include "monty.h"

/**
 * failed_malloc - failed to allocate memory
 */

void failed_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
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
	if (arguement->line)
	{
		free(arguement->line);
		arguement->line = NULL;
	}
	free_head();

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
	free_arg();
}
