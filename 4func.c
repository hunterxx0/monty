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

/**
 * rotr? (- rotates last items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void rotr(stack_t **h, unsigned int x)
{
        stack_t *t = NULL, *l = *h;

        (void)x;
        if (l && l->next)
        {
                while (l->next)
		{
			t = l;
                        l = l->next;
		}
                t->next = NULL ;
                l->prev = NULL;
                l->next = *h;
		(*h)->prev = l;
		*h = l;
        }

}

/**
 * stack? (- stack items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void stack(stack_t **h, unsigned int l)
{
	(void)h;
	(void)l;

	sq = 0;
}

/**
 * queue? (- queue items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void queue(stack_t **h, unsigned int l)
{
        (void)h;
        (void)l;

        sq = 1;
}
