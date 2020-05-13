#include "header.h"

/**
 * delnode? (- del i'th node)?
 *
 * @h: input head
 * @i: index
 * Return: 1 succes or -1 fail
 */
void pop(stack_t **h, int i)
{
	size_t x, j = 0;
	stack_t *z, *k, *t = *h;

	if (*h == NULL)
		return (-1);
	while (t)
	{
		j++;
		t = t->next;
	}
	if (i >= j)
		return (-1);
	x = 0;
	t = *h;
	if (i == 0)
	{
		if (t->next)
		{
			t = t->next;
			t->prev = NULL;
		}
		free(*h);
		*h = t;
		return (1);
	}
	while (x < i - 1)
	{
		t = t->next;
		x++;
	}
	z = t;
	t = t->next;
	z->next = t->next;
	free(t);
	if (z->next)
	{
		k = z->next;
		k->prev = z;
	}
	return (1);
}

/**
 * listsl? (- len doubly list)?
 *
 * @h: input head
 * @z: 1 for len 0 for sum
 * Return: n
 */
int listsl(const stack_t *h, int z)
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
}

/**
 * add? (- add node at the beginning)?
 *
 * @h: input head
 * @n: input node
 * Return: n
 */
stack_t *push(stack_t **h, int n)
{
	stack_t *z = (stack_t *)malloc(sizeof(stack_t));

	if (z == NULL)
		return (NULL);
	if (*h)
		(*h)->prev = z;
	z->n = n;
	z->next = *h;
	z->prev = NULL;
	*h = z;
	return (z);
}

/**
 * addend? (- add node at the end)?
 *
 * @h: input head
 * @n: input node
 * Return: z
 */
stack_t *addend(stack_t **h, const int n)
{
	stack_t *z = (stack_t *)malloc(sizeof(stack_t));
	stack_t *t = *h;

	if (z == NULL)
		return (NULL);
	z->n = n;
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
	return (z);
}

/**
 * printl? (- print doubly list)?
 *
 * @h: input head
 * Return: n
 */
int printl(const stack_t *h)
{
	int x = 0;

	while (h)
	{
		printf("%d\n", h->n);
		x++;
		h = h->next;
	}
	return (x);
}
/**
 * printl? (- print doubly list)?
 *
 * @h: input head
 * Return: n
 */
void pint(const stack_t *h)
{
	if (h)
	printf("%d\n", (*h)->n);
}
void *swap(stack_t **h)
{
	int val1, val2;

	val1 = (*h)->n;
	val2 = *(h->next)->n;
	pop(h,val1);
	pop(h,val2);
	addend(*h,val1);
	addend(*h,val2);
}
void add(stack_t **h)
{
	stack_t *tmp = *h;
	int new_somme = 0;
	new_somme = *(tmp)->n + *(tmp->next)->n;
	pop(*h,tmp->n);
	pop(*h,tmp->next->n);
	push(*h,new_somme);
}

void _nop(stack_t **h)
{
	(void)h;
	return;
}
void sub(stack_t **h)
{
int longueur = 0;
longueur = listsl(*h); 
if ( longueur >= 2)
{
	int res = (*h->next)->n - (*h)->n;
	_pop(h);
	_pop(h);
	*h->n = res;
}
}