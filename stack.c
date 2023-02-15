#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


static void __push_char(stack_c *st, char val)
{
	node_c *new_node = (node_c *) malloc(sizeof(node_c ));
	if(!new_node)
	{
		perror("Memory allocation failure\n");
		exit(1);
	}
	new_node->data = val;
	new_node->next = st->head;
	st->head = new_node;
	st->sz++;
}
static void __pop_char(stack_c *st)
{
	if(st->head == NULL)
		return;
	node_c *temp = st->head;
	st->head = temp->next;
	free(temp);
	st->sz--;
}
static char __top_char(stack_c *st)
{
	if(!st->head)
	{
		printf("Stack is empty. Returning error value -1\n");
		return -1;
	}
	return st->head->data;
}
static _Bool __empty_char(stack_c *st)
{
	return !st->sz;
};
static size_t __size_char(stack_c *st)
{
	return st->sz;
}
stack_c *init_stack_c()
{
	stack_c *new_stack = (stack_c*) malloc(sizeof(stack_c));
	new_stack->head = NULL;
	new_stack->sz = 0;
	new_stack->push = __push_char;
	new_stack->pop = __pop_char;
	new_stack->top = __top_char;
	new_stack->empty = __empty_char;
	new_stack->size = __size_char;
	return new_stack;
}
void delete_stack_char(stack_c *st)
{
	node_c *ptr = st->head;
	while(ptr)
	{
		node_c *tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(st);
}

void __push_double(stack_f *st, double val)
{
	node_f *new_node = (node_f *) malloc(sizeof(node_f));
	if(!new_node)
	{
		perror("Memory allocation failure\n");
		exit(1);
	}
	new_node->data = val;
	new_node->next = st->head;
	st->head = new_node;
	st->sz++;
}
void __pop_double(stack_f *st)
{
	if(st->head == NULL)
		return;
	node_f *temp = st->head;
	st->head = temp->next;
	free(temp);
	st->sz--;
}
double __top_double(stack_f *st)
{
	if(!st->head)
	{
		printf("Stack is empty. Returning error value -1\n");
		return -1;
	}
	return st->head->data;
}
_Bool __empty_double(stack_f *st)
{
	return !st->sz;
};
size_t __size_double(stack_f *st)
{
	return st->sz;
}
stack_f *init_stack_f()
{
	stack_f *new_stack = (stack_f*) malloc(sizeof(stack_f));
	new_stack->head = NULL;
	new_stack->sz = 0;
	new_stack->push = __push_double;
	new_stack->pop = __pop_double;
	new_stack->top = __top_double;
	new_stack->empty = __empty_double;
	new_stack->size = __size_double;
	return new_stack;
}
void delete_stack_double(stack_f *st)
{
	node_f *ptr = st->head;
	while(ptr)
	{
		node_f *tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(st);
}
