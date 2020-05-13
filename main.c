#include "header.h"

/**
 * get_func - checks if the function exists
 *
 * @cmd: command
 *
 * Return: 0 or 1
 */
void (*get_func(char *s))(stack_t **h, unsigned int n);
{
	ins_t op[] = {
		{"push", push},
		{"pall", printl},
		{"pint", printh},
		{"pop", delnode},
		{"swap", swap},
		{"add", add},
		{"nop", not},
		{"sub", sub},
		{NULL, NULL},
	};
	int i = 0;

	while (op[i].opcode)
	{
		if (*s == *(op[i].opcode))
			return(ops[i].f);
		i++;
	}

}

/**
 * checkins - checks if the function exists
 *
 * @cmd: command
 *
 * Return: 0 or 1
 */
int checkins(char *cmd)
{
char *codes[] = {
	"push",
	"pall",
	"pint",
	"pop",
	"swap",
	"add",
	"nop",
	NULL,
};
	int i = 0;

	while (codes[i])
	{
		if (!strcmp(cmd, codes[i]) && !strcmp(codes[i], "push"))
			return (99);
		if (!strcmp(cmd, codes[i]))
			return (1);
		else if (!strcmp(cmd, codes[i]) && !codes[i + 1])
			return (0);
		i++;
	}
	return (0);
}
/**
 * execins - exec instruction
 *
 * @lines: file lines
 *
 * Return: 0 or 1
 */

int execins(char **lines, stack_s **h)
{
	int i = 0, w = 0, l = 1, n = 0, c = 0;
	char **cmd = NULL;

	while (lines[i])
	{
		w = words(lines[i], ' ');
		if (!chech_push (w))
			return (1);
		i++;
		l++;
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
        int fd = 0, r = 0, w = 0;
	char **lines = NULL, file[4096];
	stack_t *head = NULL;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	r = read(fd, file, 4096);
	file[r] = '\0';
	w = words(file, '\n');
	if (w != 0)
	{
		lines = split(file, '\n', w);
		if (!lines)
		{
			fprintf(stderr,"Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		if (!execins(lines, &head))
			exit(EXIT_FAILURE);
	}

	close(fd);
	free_all(lines, head);
	return (0);
}
