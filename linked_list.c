#include "monty.h"

/**
 * add_node - add a new node to a circular linked list
 * @stack: double pointer to the beginning of the circular linked list
 * @n: value to add to the new node
 *
 * Description: the function will add the node to the begining if in
 * stack mode and the end if in queue mode
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (*stack == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	if (var.queue == STACK || var.stack_len == 0)
		*stack = new_node;
	return (new_node);
}
