#include "monty.h"

/**
 * push - function to push num to stack filo style
 * @stack: pointer to linked list
 * @line_number: input number
 */
void push(stack_t **stack, unsigned int line_number)
{
	num_t number;
       number.n	= line_number;
add_node(stack, number.n);
}
/**
 * pall - functiom to print stack
 * @stack: stack
 * @line_number: input number
 * Return: voind
 * */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;

while (current != NULL)
{
fprintf(stdout,"%d\n", current->n);
fflush(stdout);
current = current->next;
}
}
