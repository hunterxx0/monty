#include "header.h"

/**
 * free_mat - free a multidimensional array.
 *
 * @commands : array of commands.
 *
 * Return: Void.
 */

void free_mat(char **commands)
{
	int i = 0;

	if (commands)
	{
	while (commands[i])
		free(commands[i++]);
	free(commands);
	}
}


/**
 * free_list - Free a list.
 * @head : first element of the list.
 * Return : Void.
 */

void free_list(stack_t *h)
{
	stack_t *l = NULL;

	while (h)
	{
		l = h;
		h = h->next;
		free(l);
	}
}


/**
 * free_all - free evry malloc.
 * @buffer : input line.
 * @head : first element of the list.
 * @env : lists of the envirement variables.
 * Return: Void.
 */

void free_all(char **b, stack_t *h)
{
	free_mat(b);
	free_list(h);
}
