#include "monty.h"
/**
* execute - execut-the--pcode
* @stack: head-lnked list stack
* @counter: line_conter
* @file: poiner-to-monty-file
* @content: line-content
* Return: no-return
*/
int execute(char *cntnt, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opt[] = {
{"push", r_push}, {"pall", r_pall}, {"pint", r_pint},
{"pop", r_pop},
{"swap", r_swap},
{"add", r_add},
{"nop", r_nop},
{"sub", r_sub},
{"div", r_div},
{"mul", r_mul},
{"mod", r_mod},
{"pchar", r_pchar},
{"pstr", r_pstr},
{"rotl", r_rotl},
{"rotr", r_rotr},
{NULL, NULL}
};
unsigned int i = 0;
char *tok;

tok = strtok(cntnt, " \n\t");
if (tok && tok[0] == '#')
return (0);
buas.arg = strtok(NULL, " \n\t");

while (opt[i].opcode && tok)
{
if (strcmp(tok, opt[i].opcode) == 0)
{
opt[i].f(stack, counter);
return (0);
}
i++;
}
if (tok && opt[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, tok);
fclose(file);
free(cntnt);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
stack_t *tep;

tep = head;
while (head)
{
tep = head->next;
free(head);
head = tep;
}
}

/**
 * r_pint -function to priny data
 * @head: pointer to pnode
 * @number:input countr
 * Return : nin
 */
void r_pint(stack_t **head, unsigned int number)
{
	if (*head == NULL)

	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",number);
		fclose(buas.file);
		free(buas.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
		printf("%d\n", (*head)->n);
}

