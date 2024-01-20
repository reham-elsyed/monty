#include "monty.h"
/**
 * main - function to monty code interpreter
 * @argc: input num of arguments
 * @argv: input argument
 * Return: success
 */

int main(int argc, char *argv[])
{
FILE *file;
char *buffer;
stack_t *stack = NULL;
if (argc != 2) {
fprintf(stderr, "Error: No input file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL) {
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
buffer = _read_file(file);
execute(buffer, &stack);
free_stack(stack);
free(buffer);
fclose(file);
return (0);
}

/**
 * _read_file - function to read file
 * @file: pointer to input fire
 * Return: line string
 */
char *_read_file(FILE *file)
{
char *line = NULL;
size_t len = 0;
ssize_t read ;
long size;
fseek(file, 0, SEEK_END);
size = ftell(file);
rewind(file);
line = malloc(sizeof(char) * (size + 1));
if (line == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
while ((read = fread(line + len, 1, size - len, file)) > 0)
{
len += read;
}
line[len] = '\0';
return (line);
}

/**
 * free_stack - function to free stack
 * @stack: input linked list
 * Return: void
 */
void free_stack(stack_t *stack)
{
stack_t *temp;

while (stack != NULL)
{
temp = stack;
stack = stack->next;
free(temp);
}
}
