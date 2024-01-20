#include "monty.h"

/**
 * @execute - function to execute command
 * @buffer: input line string
 * @stack: pointer to node
 *return: void
 */
void execute(char *buffer, stack_t **stack)
{
	num_t number;
instruction_t opst[] = {{"pall", pall},{"push", push}, {NULL, NULL}};
int i = 0, counter = 1;
char *buff_copy = malloc(strlen(buffer) + 1);
char *token;

strcpy(buffer, buff_copy);
if (buff_copy == NULL)
{
fprintf(stderr, "Error: strdup failed\n");
exit(EXIT_FAILURE);
}
token = strtok(buff_copy, " \n\t");
while (token != NULL)
{
for (i = 0; opst[i].opcode != NULL; i++)
{
if (strcmp(token , "pall") == 0)
{
opst[i].f(stack, counter);
}
else if (strcmp(token, opst[i].opcode) == 0)
{
token = strtok(NULL, " \n\t");
if ( token != NULL)
{
number.n = atoi(token);
opst[i].f(stack, number.n);
}
break;
}
}
token = strtok(NULL, " \n\t");
}
free(buff_copy);
}
