#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include <math.h>
#include "stack.h"

void handle_matching_char(char c, char open_char,char* postfix, short* PIDX, stack_c *st)
{
	if(st->top(st) == open_char)
	{
		st->pop(st);
		return;
	}
	while(!st->empty(st) && st->top(st) != open_char)
	{
		postfix[(*PIDX)++] = st->top(st);
		st->pop(st);
	}
	st->pop(st);
}

static _Bool is_operator(char op)
{
	return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

char precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-': return 0;
		case '*':
		case '/': return 1;
		case '^': return 2;
		default: return -1;
	}

}

void make_postfix(char *postfix, const char *infix)
{
	int len = strlen(infix);
	short PIDX = 0;
	stack_c *st = init_stack_c();
	for (int i = 0; i < len; i++)
	{
		char c = infix[i];
		switch(c)
		{
			case '+':
			case '-':
			case '*':
			case '/':
				// code to handle operator
				while(NEED_TO_EVALUATE)
				{
					if(st->top(st) == '(' || st->top(st) == '{' || st->top(st) == '[')
						break;
					postfix[PIDX++] = st->top(st);
					st->pop(st);
				}
				st->push(st, c);
				break;
			case '^':
				while(!st->empty(st) && precedence(st->top(st)) > precedence(c))
				{
					if(st->top(st) == '(' || st->top(st) == '{' || st->top(st) == '[')
						break;
					postfix[PIDX++] = st->top(st);
					st->pop(st);
				}
				st->push(st, c);
				break;
			case '(':
			case '{':
			case '[':
				// code to handle opening bracket
				st->push(st, c);
				break;
			case ')':
				handle_matching_char(c, '(', postfix, &PIDX, st);
				break;
			case '}':
				handle_matching_char(c, '{', postfix, &PIDX, st);
				break;
			case ']':
				handle_matching_char(c, '[', postfix, &PIDX, st);
				break;
			}
		if(c >= '0' && c <= '9' || c == '.')
		{
			/* Add space for separating numbers */
			if(i != 0 && is_operator(infix[i-1]) || infix[i-1] == ' ' && postfix[PIDX-1] != ' ')
			{
				postfix[PIDX++] = ' ';
			}
			postfix[PIDX++] = c;
		}
	}
	while(! st->empty(st))
	{
		postfix[PIDX++] = st->top(st);
		st->pop(st);
	}
	delete_stack_char(st);
	postfix[PIDX] = '\0';
}

double evaluate_postfix(const char* postfix)
{
	stack_f *st = init_stack_f();
	double a, b, ans;
	int len = strlen(postfix);
	char *it;
	for(int i = 0; i < len; i++)
	{
		char c = postfix[i];
		double ans;
		if(is_operator(c))
		{
			b = st->top(st);
			st->pop(st);
			a = st->top(st);
			st->pop(st);
		}
		switch(c)
		{
			case '+':
				ans = a + b;
				st->push(st, ans);
				break;
			case '-':
				ans = a - b;
				st->push(st, ans);
				break;
			case '*':
				ans = a * b;
				st->push(st, ans);
				break;
			case '/':
				ans = a / b;
				st->push(st, ans);
				break;
			case '^':
				ans = pow(a, b);
				st->push(st, ans);
				break;
		}
		if(c >= '0' && c <= '9')
		{
			double num = strtof(postfix + i, &it);
			st->push(st, num);
			i = it - postfix - 1;
		}
	}
	
	double result = st->top(st);
	delete_stack_double(st);
	return result;
}

