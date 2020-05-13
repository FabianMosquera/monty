#include "monty.h"

global_t var;

/**
 * initialize - initialize all the variables into the struct
 * @fd: file descriptor
 */
void initialize(FILE *fd)
{
	var.placement = 1;
	var.fd = fd;
	var.buffer = NULL;
	var.head = NULL;
	var.stack = NULL;
	var.n_lines = 1;
}
/**
 * check_file - if the argument represent a file
 * @argc: arguments
 * @argv: reference to argument
 * Return: File desriptor
 */
FILE *check_file(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/**
 * main - function to execute the functions
 * @argc: arguments
 * @argv: referenc to argument
 * Return: exit
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t size = 128;
	ssize_t line_num = 0;
	char *args[2] = {NULL, NULL};
	void (*f)(stack_t **head, unsigned int line_number);

	fd = check_file(argc, argv);
	initialize(fd);
	line_num = getline(&var.buffer, &size, fd);
	while (line_num != -1)
	{
		args[0] = strtok(var.buffer, " \n\t");
		if (args[0][0] != '#' && args[0])
		{
			f = implement_func(args[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", var.n_lines);
				dprintf(2, "unknown instruction %s\n", args[0]);
				free_var();
				exit(EXIT_FAILURE);
			}
			var.stack = strtok(NULL, " \n\t");
			f(&var.head, var.n_lines);
		}
		line_num = getline(&var.buffer, &size, fd);
		var.n_lines++;
	}
	free_var();
	return (0);
}
