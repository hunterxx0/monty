#include "monty.h"

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
 * checkstr - if str is a number
 *
 * @h: command
 * @l: cmd len
 *
 * Return:
 */
void checkstr(stack_t **h, int l)
{
	int i = 0;

	while (cmd[1][i])
	{
		if (!isdigit(cmd[1][i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", l);
			free_all(lines, cmd, *h);
			exit(EXIT_FAILURE);
		}
	      i++;
	}

	kn = atoi(cmd[1]);
	Num = &kn;

}
