#include "monty.h"
  void pall(stack_t **stack, unsigned int line_number) {
      stack_t *temp = *stack;
      while (temp != NULL) {
          printf("%d\n", temp->n);
          temp = temp->next;
      }
  }

void push(stack_t **stack, unsigned int line_number, char *arg) {
      int n = atoi(arg);
      if (!isdigit(*arg)) {
          fprintf(stderr, "L%d: usage: push integer\n", line_number);
          exit(EXIT_FAILURE);
      }
      if (n > INT_MAX || n < INT_MIN) {
          fprintf(stderr, "L%d: usage: push integer\n", line_number);
          exit(EXIT_FAILURE);
      }
      add_node(stack, line_number, n);
  }

void add_node(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	 (*stack)->prev = new_node;
}
