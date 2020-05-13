#include "header.h"

char **lines = NULL;
char **cmd = NULL;
int *Num = NULL;
int kn = 0;

/**
 * getf - checks if the function exists
 *
 * @s: command.
 * @h: head.
 * @l: line number.
 *
 * Return: f
 */
void (*getf(char *s, stack_t *h, unsigned int l))(stack_t **h, unsigned int l)
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
		{NULL, NULL},
	};
	int i = 0;

	while (op[i].opcode)
	{
		if (!strcmp(s, op[i].opcode))
			return (op[i].f);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", l, s);
	free_all(lines, cmd, h);
	exit(EXIT_FAILURE);


}

/**
 * execins - exec instruction
 *
 * @h: head
 *
 * Return:
 */

void execins(stack_t **h)
{
	int i = 0, w = 0, l = 1;
	char **o = NULL;

	while (lines[i])
	{
		w = words(lines[i], ' ');
		if (w)
		{
			cmd = split(lines[i], ' ', w, *h);
			if (!cmd)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free_all(lines, cmd, *h);
				exit(EXIT_FAILURE);
			}
		}
		if (cmd)
		{
			getf(cmd[0], *h, l)(h, l);
			o = cmd;
			cmd = NULL;
			free_mat(o);
		}
		else
			break;
		i++;
		l++;
	}
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
	int fd = 0, r = 0, w = 0;
	char file[4096];
	stack_t *h = NULL;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_all(lines, cmd, h);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all(lines, cmd, h);
		exit(EXIT_FAILURE);
	}
	r = read(fd, file, 4096);
	file[r] = '\0';
	w = words(file, '\n');
	if (w != 0)
	{
		lines = split(file, '\n', w, h);
		execins(&h);
	}
	close(fd);
	free_all(lines, cmd, h);
	return (0);
}
