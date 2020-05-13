#include "monty.h"

/*
*
*
*
*/
void fn_div(stack_t **h, unsigned int l)
{
	stack_t *tmp = *h;
	int res = 0;

	if (listsl(tmp, 1) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if ((tmp)->n != 0)
	{
		res = (((tmp)->next)->n) / ((tmp)->n);
		*h = tmp->next;
		tmp->next->n = res;
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
}
/*
*
*
*
*
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
	tmp = tmp->next;
	tmp->n = res;
	*h = tmp;
	free(tmp);
	}
}

/*
*
*
*
*
*/
void mod (stack_t **h, unsigned int l)
{
	stack_t *tmp = *h;
	int val1 = 0, val2 = 0, res = 0;

	if (listsl(tmp, 1) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	if(tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", l);
		fclose(fd);
		free_all(file, cmd, *h);
		exit(EXIT_FAILURE);
	}
	else
	{
		val1 = tmp->next->n;
		val2 = tmp->n;
		res = val2 % val1;
		tmp = tmp->next;
		tmp->n = res;
		*h = tmp;
		free(tmp);

	}

}