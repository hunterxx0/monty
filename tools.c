#include "monty.h"

/**
* words - return the number of words in a string.
*
* @c : string of words.
* @x : delimiter between the words.
*
* Return: Integer(mean true)
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
 * checkstr - if str is a number
 *
 * @h: command
 * @l: cmd len
 *
 * Return:nothing (mean true)
 */
void checkstr(stack_t **h, int l)
{
	int i = 0;

	if (i == 0 && cmd[1][i] == '-')
		i++;
	while (cmd[1][i])
	{
		if (!isdigit(cmd[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", l);
			free_all(file, cmd, *h);
			exit(EXIT_FAILURE);
		}
	      i++;
	}

	kn = atoi(cmd[1]);
	Num = &kn;

}
