int chech_push (int w)
{
if (w)
		{
			cmd = split(lines[i], ' ', w);
			if (!cmd)
			{
			fprintf(stderr,"Error: malloc failed\n");
				return (0);
			}
			c = checkins(cmd[0])
			if (!c)
				{
		fprintf(stderr,"L%d: unknown instruction %s\n", l, cmd[0]);
					return (0);
				}
			else if (c == 99)
				if (cmd[1])
				{
					if (c = strlen(cmd[1]) > 0)
						{
		if (!checkstr(cmd[1], c))
                {
		fprintf(stderr,"L%d: unknown instruction %s\n", l, cmd[0]);
                        return (0);
                }
		else
			n = atoi(cmd[1]);
						}

				}
				else
				{
		fprintf(stderr,"L%d: usage: push integer\n", l);
					return (0);
				}
			get_func(cmd[0])(h, n);
			if (!get_func(cmd[0])(h, n)))
				give_me_error((cmd[0])(h, n))
		}
}
/**
 * give_me_error - print the error expected
 *
 * @cmd: command
 *
 * Return: 0 or 1
 */

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
