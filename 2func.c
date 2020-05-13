#include "monty.h"

/**
 * pop? (- del first node)?
 *
 * @h: input head
 * @l: line
 * Return: 1 succes or -1 fail
 */
void pop(stack_t **h, unsigned int l)
{
	stack_t *t = (*h)->next;

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if (!t)
	{
		free(*h);
		return;
	}
	t->prev = NULL;
	free(*h);
	*h = t;
}

/**
 * listsl? (- len doubly list)?
 *
 * @h: input head
 * @z: 1 for len 0 for sum
 * Return: n or x
 */
int listsl(stack_t *h, int z)
{
	int n = 0, x = 0;

	while (h)
	{
		x++;
		n += h->n;
		h = h->next;
	}
	if (z == 1)
		return (x);
	if (z == 0)
		return (n);
	return (0);
}

/**
 * push? (- add node at the beginning)?
 *
 * @h: input head
 * @l: input node
 * Return: n
 */
void push(stack_t **h, unsigned int l)
{
	stack_t *z = (stack_t *)malloc(sizeof(stack_t));
	int x = 0;

	if (z == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if (!cmd[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	else
		checkstr(h, l);
	if (!Num)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	else
		x = *Num;
	if (*h)
		(*h)->prev = z;
	z->n = x;
	z->next = *h;
	z->prev = NULL;
	*h = z;
}

/**
 * addend? (- add node at the end)?
 *
 * @h: input head
 * @l: line
 * Return: z
 */
void addend(stack_t **h, unsigned int l)
{
	stack_t *z = (stack_t *)malloc(sizeof(stack_t));
	stack_t *t = *h;

	(void)l;
	if (z == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	z->n = 0;
	z->next = NULL;
	if (*h == NULL)
		*h = z;
	else
	{
	while (t->next)
		t = t->next;
	t->next = z;
	z->prev = t;
	}
}

/**
 * pall? (- print all)?
 *
 * @h: input head
 * @l: line num
 * Return: n
 */
void pall(stack_t **h, unsigned int l)
{
	stack_t *t = *h;

	(void)l;
	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}
