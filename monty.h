#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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
 *
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
 * struct args_s - contains arguement
 * @stream: steam from which file is read
 * @line: line read from file or stream
 * @l_num: position of opcode
 * @token: broken strings
 * @token_number: number of tokens
 * @line_len: length of each opcode line
 * @instruct: opcode
 * @head: node list that holds data
 * @stack_len: length of node
 */

typedef struct args_s
{
	FILE *stream;
	char *line;
	unsigned int l_num;
	char **token;
	int token_number;
	size_t line_len;
	instruction_t *instruct;
	stack_t *head;
	int stack_len;
} args_t;

extern int argc;
extern char **argv;
extern args_t *arguement;
extern stack_t *stack;

void check_arg(int argc);
void failed_malloc(void);
void free_arg(void);
void initialize_arg(void);
void open_file(char *filename);
void open_failed(char *filename);
void tokenizer(void);
void tokenizer(void);
void which_instruct(void);
void invalid_ins(void);
void stream_closed(void);
void free_token(void);
void action(stack_t **stack);
void free_head(void);
int _num(char *str);
void free_stack(stack_t *head);
void free_all_arg(void);

void push(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);

#endif /*MONTY_H*/
