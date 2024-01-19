#include "monty.h"
/**
 * addnode - add nod tothe--headtack
 * @head: head of input atacj stack
 * @n: new_value to node
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

stack_t *new_node, *tem;

tem = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{ printf("Error\n");
exit(0);
}
if (tem)
tem->prev = new_node;
new_node->n = n;
new_node->next = *head;
new_node->prev = NULL;
*head = new_node;
}
