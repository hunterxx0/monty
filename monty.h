#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **, unsigned int);
} ins_t;


extern int kn;
extern int *Num;
extern char *file;
extern char **cmd;
extern FILE *fd;

int words(char *, char);
void checkstr(stack_t **, int);
char **split(char *, char, int, stack_t *);
void free_mat(char **);
void free_list(stack_t *);
void free_all(char *, char **, stack_t *);
int listsl(stack_t *, int);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
int listsum(stack_t *, int);
void fn_div(stack_t **, unsigned int);
void fn_mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

#endif /* HEADER_H */
