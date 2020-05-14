#include "monty.h"

/**
 * rotl? (- rotates first items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void rotl(stack_t **h, unsigned int l)
{
	stack_t *t = *h, *f = *h;

	(void)l;
	if (t && t->next)
	{
		(*h) = (*h)->next;
		while (t->next)
			t = t->next;
		t = t->next = f;
		f->prev = t;
		f->next = NULL;
	}

}
