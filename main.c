#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"
#include "stack.h"
#define LENGTH 1001


int main(void)
{
	char infix[LENGTH];
	char postfix[LENGTH];
	printf(":: A simple calculator\n:: Press 'q' to exit\n");
	_Bool run = 1;
	while(run)
	{
		printf("## Calculate: ");
		fgets(infix, LENGTH, stdin);
		if(infix[0] == 'q' || infix[0] == 'Q')
			return 0;
		make_postfix(postfix, infix);
		printf("%s\n", postfix);
		double ans = evaluate_postfix(postfix);
		printf("%lf\n", ans);
	}
	return 0;
}

