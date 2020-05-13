#include "header.h"

/**
 * allocation - allocate a space memory for a pointer.
 * @p : pointer to ponter of string.
 * @i : current row of "p".
 * @width : width of the current row.
 * Return: 1 or 0.
 */

void allocation(char **p, int i, int width, stack_t *h)
{
	p[i] = malloc(sizeof(char) * (width + 1));
	if (p[i] == NULL)
	{
		for (i -= 1; i >= 0; i--)
			free(p[i]);
		free(p);
		fprintf(stderr,"Error: malloc failed\n");
		free_all(lines, cmd, h);
		exit(EXIT_FAILURE);
	}

}


/**
 * **split - function that splits a string into words.
 * @str : string.
 * @del : delimiter.
 * @heigth : number of words.
 * Return: pointer.
 */

char **split(char *str, char del, int heigth, stack_t *h)
{
	int i, j = 0, k = 0, l, width;
	char **p = NULL;

	if (str == NULL || *str == '\0')
		return (NULL);

	p = malloc(sizeof(char *) * (heigth + 1));
	if (p == NULL)
	{
		fprintf(stderr,"Error: malloc failed\n");
		free_all(lines, cmd, h);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < heigth; i++)
	{

		while (str[j] == del && str[j] != '\0')
			j++;

		width = 0;
		k = j;

		while (str[k] != del && str[k] != '\0')
		{
			width++;
			k++;
		}
		allocation(p, i, width, h);
		for (l = 0; l < width; l++, j++)
			p[i][l] = str[j];
		p[i][l] = '\0';
	}
	p[i] = NULL;
	return (p);
}
