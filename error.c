void error_push(unsigned int line_nbr)
{
	printf("L%d: usage: push integer\n", line_nbr);
	exit(EXIT_FAILURE);
}
void error_printh(unsigned int line_nbr)
{
	printf("L%d: can't pint, stack empty\n", line_nbr);
	exit(EXIT_FAILURE);
}
void error_delnode(unsigned int line_nbr)
{
	printf("L%d: can't pop an empty stack\n", line_nbr);
	exit(EXIT_FAILURE);
}
void error_swap(unsigned int line_nbr)
{
	printf("L%d: can't swap, stack too short\n", line_nbr);
	exit(EXIT_FAILURE);
}
void error_add(unsigned int line_nbr)
{
	printf("L%d: can't add, stack too short\n", line_nbr);
	exit(EXIT_FAILURE);
}
void error_sub(unsigned int line_nbr)
{
	printf("L%d: can't sub, stack too short\n", line_nbr);
	exit(EXIT_FAILURE);
}