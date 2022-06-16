#include "monty.h"

/**
 * add_m - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void add_m(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	num += (*stack)->n;
	pop_m(stack, line_number);
	(*stack)->n += num;
}
