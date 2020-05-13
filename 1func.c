#include "monty.h"

/**
 * pint? (- print first item list)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void pint(stack_t **h, unsigned int l)
{
	if (!h || !*h)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
/**
 * swap? (- first 2 numbers of the list)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void swap(stack_t **h, unsigned int l)
{
	int val1, val2;

	if (listsl(*h, 1) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	val1 = (*h)->n;
	val2 = (*h)->next->n;
	(*h)->n = val2;
	(*h)->next->n = val1;
}
/**
 * add? (- first 2 numbers of the list)?
 *
 * @h: input head
 * @l: line number
 * Return: n
 */
void add(stack_t **h, unsigned int l)
{
	stack_t *tmp = (*h)->next;
	int new_somme = 0;

	if (listsl(*h, 1) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	new_somme = tmp->n + (*h)->n;
	free(*h);
	tmp->prev = NULL;
	tmp->n = new_somme;
	*h = tmp;
}
/**
 * nop? (- do nothing)?
 *
 * @h: input head
 * @l: line number
 * Return: n
 */
void nop(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;
}
/**
 * sub? (- first 2 numbers of the list)?
 *
 * @h: input head
 * @l: line number
 * Return: n
 */
void sub(stack_t **h, unsigned int l)
{
	int res = 0;
	stack_t *tmp = (*h)->next;

	if (listsl(*h, 1) < 2)
	{
		fprintf(stderr, "L%u: , can't sub, stack too short\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	res = tmp->n - (*h)->n;
	free(*h);
	tmp->prev = NULL;
	tmp->n = res;
	*h = tmp;
}
