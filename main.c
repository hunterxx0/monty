#include "monty.h"

char *file = NULL;
char **cmd = NULL;
int *Num = NULL;
int kn = 0;
int sq = 0;
FILE *fd;

/**
 * getf - checks if the function exists
 *
 * @s: command.
 * @h: head.
 * @l: line number.
 *
 * Return: nothing
 */
void (*getf(char **s, stack_t *h, unsigned int l))(stack_t **h, unsigned int l)
{
	ins_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", fn_div},
		{"mul", fn_mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
		{NULL, NULL},
	};
	int i = 0;

	while (op[i].opcode)
	{
		if (strcmp(s[0], op[i].opcode) == 0)
		{
			if (sq == 1 && strcmp("push", op[i].opcode) == 0)
				return (addend);
			else
				return (op[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", l, s[0]);
	fclose(fd);
	free_all(file, cmd, h);
	exit(EXIT_FAILURE);


}

/**
 * execins - exec instruction
 *
 * @h: head
 * @l: line number
 *
 * Return:
 */

void execins(stack_t **h, unsigned int l)
{
	int w = 0;
	char **o = NULL;

	w = words(file, ' ');
	if (w)
	{
		cmd = split(file, ' ', w, *h);

		if (!cmd)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_all(file, cmd, *h);
			exit(EXIT_FAILURE);
		}
		else
		{
			getf(cmd, *h, l)(h, l);
			o = cmd;
			cmd = NULL;
			free_mat(o);
		}
	}
	else
		return;
}
/**
 * checkcom - comm
 *
 * Return: 0 or 1
 */

int checkcom(void)
{
	int i = 0;

	while (file[i])
	{
		if (file[i] == ' ')
			i++;
		else if (file[i] == '#')
			return (1);
		else if (file[i] != ' ' && file[i] != '#')
			break;
	}
	return (0);
}

/**
 * main - monty main function
 *
 * @argc: arguments number
 * @argv: arguments
 *
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	int r = 0;
	unsigned int l = 1;
	char *o = NULL;
	size_t buf = 0;
	stack_t *h = NULL;


	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_all(file, cmd, h);
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all(NULL, cmd, h);
		exit(EXIT_FAILURE);
	}
	do {
		r = getline(&file, &buf, fd);
		if (r != -1)
		{
			file[r - 1] = '\0';
			if (checkcom() == 1)
				continue;
			execins(&h, l);
			o = file;
			file = NULL;
			free(o);
		}
		l++;
	} while (r != -1);
	fclose(fd);
	free_all(file, cmd, h);
	return (0);
}
