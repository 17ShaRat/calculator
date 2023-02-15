#ifndef CALC_H
#define CALC_H
#define PIDX postfix_iterator
void make_postfix(char *postfix, const char *infix);
/* returns true if the char is an arithmetic operator */
static _Bool is_operator(char op);
#define NEED_TO_EVALUATE !st->empty(st) && precedence(st->top(st)) > precedence(c)

/* return the precedence value of the op */
static char precedence(char op);
double evaluate_postfix(const char* postfix);

#endif
