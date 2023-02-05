#include<stdbool.h>
#ifndef STACK_H
#define STACK_H
/* Define linked list node for integer data type */
typedef struct node_i
{
        int data;
        struct node_i* next;
} node_i;
/* define linked_list node for char */
typedef struct node_c
{
        char data;
        struct node_c* next;
} node_c;

typedef struct node_f
{
        double data;
        struct node_f* next;
} node_f;


typedef struct stack_i
{
        node_i* head;
        int size;
        char type;
        void (*push) (struct stack_i*, int);
        void (*pop) (void *);
        int (*top) (struct stack_i*);
        bool (*empty) (struct stack_i*);
} stack_i;

typedef struct stack_c
{
        node_c* head;
        int size;
        char type;
        void (*push) (struct stack_c*, char);
        void (*pop) (void *);
        char (*top) (struct stack_c*);
        bool (*empty) (struct stack_c*);
} stack_c;

typedef struct stack_f
{
        node_f* head;
        int size;
        char type;
        void (*push) (struct stack_f*, double);
        void (*pop) (void *);
        char (*top) (struct stack_f*);
        bool (*empty) (struct stack_f*);
} stack_f;

void* new_stack(char type);
void __push_i(stack_i* st, int value);
void __push_c(stack_c* st, char value);
void __push_f(stack_f* st, double value);
void __pop(void *);
#endif
