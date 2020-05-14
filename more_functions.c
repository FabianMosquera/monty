#include "monty.h"
/**
 * stack_add - adds the two top elements
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_add(stack_t **head, unsigned int line_n)
{
	stack_t *tmp = NULL;
	int i = 0;

	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_n);
		free_var();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n += (*head)->n;
	stack_pop(head, line_n);
}
/**
 * stack_nop - doesn’t do anything.
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_nop(stack_t **head, unsigned int line_n)
{
	(void)head;
	(void)line_n;
}
/**
 * stack_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_sub(stack_t **head, unsigned int line_n)
{
	stack_t *tmp = NULL;
	int i = 0;

	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_n);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n -= (*head)->n;
	stack_pop(head, line_n);
}
/**
 * stack_div - divides the second top element of the stack
 * by the top element of the stack.
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_div(stack_t **head, unsigned int line_n)
{
	stack_t *tmp = NULL;
	int i = 0;

	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_n);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_n);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = (int)(tmp->n) / (*head)->n;
	stack_pop(head, line_n);
}
/**
 * stack_mul - multiplies the top two elements of the stack
 * @head: head to the stack
 * @line_n: Reference to the line we are checking in case of an error
 */
void stack_mul(stack_t **head, unsigned int line_n)
{
	stack_t *tmp = NULL;
	int i = 0;

	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_n);
		free_vars();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n *= (*head)->n;
	stack_pop(head, line_n);
}
