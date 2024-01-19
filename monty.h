#ifndef __MONTY_H__
#define __MONTY_H__

#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
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


/**
 * struct buas_s - variables -args, file- line-content
 * @arg: value
 * @file: pointghcgc ,lko monty file
 * @content: line tent
 * @lifi: flag change stack <-> queue
 * Description: carrs vals throh theram
 */
typedef struct buas_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  buas_t;
extern buas_t buas;

int main(int argc, char *argv[]);
FILE *_open_file(char *argv);
char *_read_file(FILE *file);
void free_stack(stack_t *head);
int execute(char *cntnt, stack_t **stack, unsigned int counter, FILE *file);
void add_node(stack_t **head, int n);
void r_push(stack_t **head, unsigned int counter);
void r_pall(stack_t **head, unsigned int counter);
void r_pint(stack_t **head, unsigned int number);
void r_pop(stack_t **head, unsigned int counter);
void r_swap(stack_t **head, unsigned int counter);
void r_add(stack_t **head, unsigned int counter);
void r_nop(stack_t **head, unsigned int counter);
void r_sub(stack_t **head, unsigned int counter);
void r_div(stack_t **head, unsigned int counter);
void r_mul(stack_t **head, unsigned int counter);
void r_mod(stack_t **head, unsigned int counter);
void r_pchar(stack_t **head, unsigned int counter);
void r_pstr(stack_t **head, unsigned int counter);
void r_rotl(stack_t **head, unsigned int counter);
void r_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

#endif
