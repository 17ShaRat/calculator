#include <stdint.h>
#include <stdio.h>
#ifndef STACK_H
#define STACK_H
typedef struct node_c node_c;
struct node_c
{
	char data;
	node_c *next;
};

typedef struct stack_c stack_c;
struct stack_c
{
	node_c *head;
	size_t sz;
	void (*push) (stack_c *, char);
	void (*pop) (stack_c *);
	_Bool (*empty) (stack_c *);
	size_t (*size) (stack_c *);
	char (*top)(stack_c *);
};

/*@param st character stack pointer to be freed */
void delete_stack_char(stack_c *st);
/* Allocates and initializes a new character stack
 * and return a pointer to it
 */
stack_c *init_stack_c();

typedef struct node_f node_f;
struct node_f
{
	double data;
	node_f *next;
};

typedef struct stack_f stack_f;
struct stack_f
{
	node_f *head;
	size_t sz;
	void (*push) (stack_f *, double);
	void (*pop) (stack_f *);
	_Bool (*empty) (stack_f *);
	size_t (*size) (stack_f *);
	double (*top)(stack_f *);
};
void delete_stack_double(stack_f *st);
stack_f *init_stack_f();
#endif
