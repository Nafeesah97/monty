#include "monty.h"

/**
 * free_token - to free tokens
 */

void free_token(void)
{
	int i = 0;

	if (arguement->token == NULL)
		return;

	while (arguement->token[i])
	{
		free(arguement->token[i]);
		i++;
	}
	free(arguement->token);
	arguement->token = NULL;
}

