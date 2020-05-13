#include "monty.h"

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
	char **o = NULL;

	if (!commands || !*commands)
		return;
	o = commands;
	commands = NULL;
	while (o[i])
		free(o[i++]);
	free(o);

}


/**
 * free_list - Free a list.
 * @h : first element of the list.
 * Return : Void.
 */

void free_list(stack_t *h)
{
	stack_t *l = NULL;

	if (!h)
		return;
	while (h)
	{
		l = h;
		h = h->next;
		free(l);
	}
}


/**
 * free_all - free evry malloc.
 * @b : input lines.
 * @h : first element of the list.
 * @c : lists of cmds.
 * Return: Void.
 */

void free_all(char *b, char **c, stack_t *h)
{
	if (b)
		free(b);
	free_mat(c);
	free_list(h);
}
