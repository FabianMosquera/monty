#include "monty.h"
/**
 * add_nodeint - add a node into a doubly linked list
 * @head: Pointer first node
 * @n: number to add
 * Return: pointer to the new node
 */
stack_t *add_nodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * add_nodeint_end - add a node into the end to a doubly linked list
 * @head: Pointer first node
 * @n: number to add
 * Return: pointer to the new node
 */
stack_t *add_nodeint_end(stack_t **head, const int n)
{
	stack_t *new, *tmp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (!(*head))
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	new->prev = tmp;
	tmp->next = new;
	return (new);
}
/**
 * free_stack - free doubly linked list
 * @head: first node of linked list
 */
void free_stack(stack_t *head)
{
	stack_t *next;

	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
}
/**
 * free_var - free struct global variables
 */
void free_var(void)
{
	free_stack(var.head);
	free(var.buffer);
	fclose(var.fd);
}
