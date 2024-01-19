#include "monty.h"
buas_t buas = {NULL, NULL, NULL, 0};
/**
 * main -function for monty code reader
 * @argc: input num
 * @argv: input atg
 * @Retur: success
 */

int main(int argc, char *argv[])
{
char *content = NULL;
FILE *f;
size_t size = 0;
ssize_t read_line = 1;
stack_t *stck = NULL;
unsigned int counter = 0;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
f = fopen(argv[1], "r");
buas.file = f;
if (!f)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (read_line > 0)
{
content = NULL;
read_line = getline(&content, &size, f);
buas.content = content;
counter++;
if (read_line > 0)
{
execute(content, &stck, counter, f);
}
}
free(content);

free_stack(stck);
fclose(f);
return (0);
}


/**
 * r_pall - prints-- the numbers in the the stack
 * @head: stack head input value
 * @counter: no 
 * Return: no rturn
*/
void r_pall(stack_t **head, unsigned int counter)
{
stack_t *hd;
(void)counter;

hd = *head;
if (hd == NULL)
return;
while (hd)
{
printf("%d\n", hd->n);
hd = hd->next;
}
}

/**
 * r_push - add-node tothe tack
 * @head: stack had
 * @counter: line_number
 * Return: noreturn value
*/
void r_push(stack_t **head, unsigned int counter)
{
int n, j = 0, flag = 0;

if (buas.arg)
{
if (buas.arg[0] == '-')
j++;
for (; buas.arg[j] != '\0'; j++)
{
if (buas.arg[j] > 57 || buas.arg[j] < 48)
flag = 1;
}
if (flag == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(buas.file);
free(buas.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(buas.file);
free(buas.content);
free_stack(*head);
exit(EXIT_FAILURE); }
n = atoi(buas.arg);
if (buas.lifi == 0)
add_node(head, n);
}
