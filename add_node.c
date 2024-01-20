#include "monty.h"
/**
 * addnode - add nod tothe--headtack
 * @stack: head of input atacj stack
 * @line_number: new_value to node
 * Return: no return
*/
stack_t *add_node(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = line_number;
new_node->next = *stack;
new_node->prev = NULL;

if (*stack != NULL)
{
(*stack)->prev = new_node;
}
*stack = new_node;
printf("nodecraeted %d\n", new_node->n);
return (*stack);
}
