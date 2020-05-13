#include "header.h"


/**
* words - return the number of words in a string.
*
* @c : string of words.
* @x : delimiter between the words.
*
* Return: Integer.
*/

int words(char *c, char x)
{
	int w = 0, i = 0;

	while (c[i] != '\0')
	{
		if (c[i] != x)
		{
			if (c[i] == '#' && c[i])
			{
				c[i] = '\0';
				break;
			}
			w++;
			while (c[i] != x && c[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w);
}

/**
 * checkstr - checks if the function exists
 *
 * @cmd: command
 * @c: cmd len
 *
 * Return: 0 or 1
 */
void checkstr(stack_t **h, int l)
{
	int i = 0, n = 0;

	while (cmd[1][i])
	{
		if (!isdigit(cmd[1][i]))
		{
			fprintf(stderr,"L%d: usage: push integer\n", l);
			free_all(lines, cmd, *h);
			exit(EXIT_FAILURE);
		}
	      i++;
	}

	n = atoi(cmd[1]);
	Num = &n;

}

/**
 * give_me_error - print the error expected
 *
 * @cmd: command
 *
 * Return: 0 or 1


void (*give_me_error(char *s))(stack_t **h, unsigned int n)
{
	ins_t op[] = {
		{"push", error_push},
		{"pint", error_printh},
		{"pop", error_delnode},
		{"swap", error_swap},
		{"add", error_add},
		{"sub", error_sub},
		{NULL, NULL},
	};
	int i = 0;
	while (op[i].opcode)
	{
		if (*s == *(op[i].opcode))
			return(ops[i].f(n));
		i++;
	}
}
*/
