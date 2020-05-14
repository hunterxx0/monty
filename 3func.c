#include "monty.h"

/**
 * fn_div? (- div first items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void fn_div(stack_t **h, unsigned int l)
{
	stack_t *tmp = *h;
	int res = 0;

	if (!h || !(*h) || !(*h)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n != 0)
	{
		*h = (*h)->next;
		res = (*h)->n / tmp->n;
		(*h)->n = res;
		(*h)->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
}

/**
 * fn_mul? (- mul first items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */


void fn_mul(stack_t **h, unsigned int l)
{
	stack_t *tmp = *h;
	int val1 = 0, val2 = 0, res = 0;

	if (listsl(tmp, 1) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);

	}
	else
	{
	val1 = tmp->n;
	val2 = tmp->next->n;
	res = val2 * val1;
	tmp->next->n = res;
	*h = tmp->next;
	free(tmp);
	}
}

/**
 * mod? (- mod first items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void mod (stack_t **h, unsigned int l)
{
	stack_t *tmp = *h;
	int res = 0;


        if (!h || !(*h) || !(*h)->next)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", l);
                fclose(fd);
                free_all(file, cmd, *h);
                exit(EXIT_FAILURE);
        }
        if ((*h)->n != 0)
        {
                *h = (*h)->next;
                res = (*h)->n % tmp->n;
                (*h)->n = res;
                (*h)->prev = NULL;
                free(tmp);
        }
        else
        {
                fprintf(stderr, "L%u: division by zero\n", l);
                fclose(fd);
                free_all(file, cmd, *h);
                exit(EXIT_FAILURE);
        }


}

/**
 * pchar ? (- mod first items)?
 *
 * @h: input head
 * @l: line number
 * Return:
 */
void pchar(stack_t **h, unsigned int l)
{

	if (!h || !*h)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n < 0 || (*h)->n > 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", (*h)->n);
}
