#include "monty.h"
/**
 * stack_push - function that add a new node into doubly linked list
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_push(stack_t **head, unsigned int line_n)
{
	int number = 0;
	int i = 0;

	if (!var.stack)
	{
		dprintf(2, "L%u: ", line_n);
		dprintf(2, "usage: push integer\n");
		free_var();
		exit(EXIT_FAILURE);
	}

	while (var.stack[i] != '\0')
	{
		if ((!(isdigit(var.stack[i]))) && var.stack[i] != '-')
		{
			dprintf(2, "L%u: ", line_n);
			dprintf(2, "usage: push integer\n");
			free_var();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	number = atoi(var.stack);
	if (var.placement == 1)
		add_nodeint(head, number);
	else
		add_nodeint_end(head, number);
}
/**
 * stack_pall - function that print all values
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_pall(stack_t **head, unsigned int line_n)
{
	stack_t *tmp;
	(void)line_n;
	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * stack_pint - print only the value
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_pint(stack_t **head, unsigned int line_n)
{
	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_n);
		dprintf(2, "can't pint, stack empty\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * stack_pop - removethe top element
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_pop(stack_t **head, unsigned int line_n)
{
	stack_t *tmp;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_n);
		free_var();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
/**
 * stack_swap - sawp the two top element
 * @head: head of doubly linked list
 * @line_n: Reference to the line of doubly linked list
 */
void stack_swap(stack_t **head, unsigned int line_n)
{
	int i = 0;
	stack_t *tmp = NULL;

	tmp = *head;

	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_n);
		free_var();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}
