#ifndef __MONTY_H__
#define __MONTY_H__

#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#define POSIX .1-2008
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *struct numbers_s - input numbers
 *@n: number
 */
typedef struct numbers_s {
  unsigned int n;
} num_t;

char *_read_file(FILE *file);
void free_stack(stack_t *stack);
stack_t *add_node(stack_t **stack, unsigned int line_number);
void execute(char *buffer, stack_t **stack);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);

#endif
