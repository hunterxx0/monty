#include "header.h"

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
		fprintf(stderr,"L%u: can't pop an empty stack\n", l);
		free_all(lines, cmd, *h);
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
 * @n: input node
 * Return: n
 */
void push(stack_t **h, unsigned int l)
{
	stack_t *z = (stack_t *)malloc(sizeof(stack_t));
	int x = 0;

	if (z == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if (!cmd[1])
	{
		fprintf(stderr,"L%d: usage: push integer\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	else
		checkstr(h, l);
	if (!Num)
	{
		fprintf(stderr,"L%u: usage: push integer\n", l);
		free_all(lines, cmd, *h);
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
		fprintf(stderr,"Error: malloc failed\n");
		free_all(lines, cmd, *h);
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

/**
 * pint? (- print doubly list)?
 *
 * @h: input head
 * Return: n
 */
void pint(stack_t **h, unsigned int l)
{
	if (!h)
	{
		fprintf(stderr,"L%u: can't pint, stack empty\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
void swap(stack_t **h, unsigned int l)
{
	int val1, val2;

	if (listsl(*h, 1) < 2)
	{
		fprintf(stderr,"L%u: can't swap, stack too short\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	val1 = (*h)->n;
	val2 = (*h)->next->n;
	(*h)->n = val2;
	(*h)->next->n = val1;
}
void add(stack_t **h, unsigned int l)
{
	stack_t *tmp = (*h)->next;
	int new_somme = 0;

	if (listsl(*h, 1) < 2)
	{
		fprintf(stderr,"L%u: can't add, stack too short\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	new_somme = tmp->n + (*h)->n;
	free (*h);
	tmp->prev = NULL;
	tmp->n = new_somme;
	*h = tmp;
}

void nop(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;
	return;
}
void sub(stack_t **h, unsigned int l)
{
	int res = 0;
	stack_t *tmp = (*h)->next;

	if (listsl(*h, 1) < 2)
	{
		fprintf(stderr,"L%u: , can't sub, stack too short\n", l);
		free_all(lines, cmd, *h);
		exit(EXIT_FAILURE);
	}
	res = tmp->n - (*h)->n;
	free (*h);
	tmp->prev = NULL;
	tmp->n = res;
	*h = tmp;
}
