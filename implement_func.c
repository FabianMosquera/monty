#include "monty.h"
/**
 * implement_func - get the option input
 * @str: input opcode
 * Return: stack
 */
void (*implement_func(char *str))(stack_t **head, unsigned int line_n)
{
	int i = 0;
	instruction_t stack[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{NULL, NULL}
	};

	while (stack[i].opcode)
	{
		if (strcmp(stack[i].opcode, str) == 0)
			break;
		i += 1;
	}
	return (stack[i].f);
}
