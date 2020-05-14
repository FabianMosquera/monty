#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_v - opcode and its function
 * @placement: order of the stack
 * @fd: file descriptor
 * @n_lines: lines into file
 * @buffer: allocate the data of each line
 * @stack: stack will be added
 * @head: head of linked list
 */
typedef struct global_v
{
	int placement;
	FILE *fd;
	char *buffer;
	char *stack;
	unsigned int n_lines;
	stack_t *head;
} global_t;

extern global_t var;
/*function mandatory */
void (*implement_func(char *str))(stack_t **head, unsigned int line_n);
void stack_push(stack_t **head, unsigned int line_n);
void stack_pall(stack_t **head, unsigned int line_n);
void stack_pint(stack_t **head, unsigned int line_n);
void stack_pop(stack_t **head, unsigned int line_n);
void stack_swap(stack_t **head, unsigned int line_n);
/*Linked list */
stack_t *add_nodeint(stack_t **head, const int n);
stack_t *add_nodeint_end(stack_t **head, const int n);
/*free*/
void free_stack(stack_t *head);
void free_var(void);
/*init the executable*/
void initialize(FILE *fd);
FILE *check_file(int argc, char **argv);
#endif /* MONTY_H */
