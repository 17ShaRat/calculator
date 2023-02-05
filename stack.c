#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void* new_stack(char type)
{
        void* n_stack;
        if(type == 'i')
        {
                n_stack = malloc(sizeof(struct stack_i));
                stack_i* temp_i = n_stack;
                temp_i->head = NULL;
                temp_i->size = 0;
                temp_i->type = type;
                temp_i->push = __push_i;
                temp_i->pop = __pop;
        }
        else if(type == 'c')
        {
                n_stack = malloc(sizeof(struct stack_c));
                stack_c* temp_c = n_stack;
                temp_c->head = NULL;
                temp_c->size = 0;
                temp_c->type = type;
                temp_c->push = __push_c;
                temp_c->pop = __pop;
        }
        else if(type == 'f')
        {
                n_stack = malloc(sizeof(struct stack_f));
                stack_f* temp_f = n_stack;
                temp_f->head = NULL;
                temp_f->size = 0;
                temp_f->type = type;
                temp_f->push = __push_f;
                temp_f->pop = __pop;
        }

        return n_stack;
}

void __push_i(stack_i* st, int value)
{
        node_i* n = (node_i*) malloc(sizeof *n);
        n->data = value;
        n->next = st->head;
        st->head = n;
        st->size++;
}
void __push_c(stack_c* st, char value)
{
        node_c* n = (node_c*) malloc(sizeof *n);
        n->data = value;
        n->next = st->head;
        st->head = n;
        st->size++;
}
void __push_f(stack_f* st, double value)
{
        node_f* n = (node_f*) malloc(sizeof *n);
        n->data = value;
        n->next = st->head;
        st->head = n;
        st->size++;
}
void __pop(void *st)
{
        stack_i* s = (stack_i *)st;
        if(s->head)
        {
                void* t = s->head->next;
                free(s->head);
                s->head = t;
                s->size--;
        }

}
