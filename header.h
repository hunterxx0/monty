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
        void (*f)(stack_t **stack, int line);
} ins_t;

int words(char *, char);
char **split(char *, char, int);
void free_mat(char **);
void free_list(stack_t *);
void free_all(char **, stack_t *);
void listsl(stack_t *, int);
void printl(stack_t *, int);
void printh(stack_t *, int)
void push(stack_t *, int);
void add(stack_t *, int)
int listsum(stack_t *, int);
void pop(stack_t **, int);



#endif /* LISTS_H */
