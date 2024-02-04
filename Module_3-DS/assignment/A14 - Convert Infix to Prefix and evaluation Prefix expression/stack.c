#include "main.h"

void push(Stack_t *stk, int data)
{
	++(stk -> top);
	stk -> stack[stk -> top] = data;
}

void pop(Stack_t *stk)
{
	if (stk -> top != -1)
		--(stk -> top);
}

int peek(Stack_t *stk)
{
	if (stk -> top != -1)
	{
		return stk -> stack[stk -> top];
	}
	return -1;
}

/* Function to check the precedence of operators. */
int priority(char opr)
{
	if( opr == '*' || opr == '/' || opr == '%')
	{
		return 2;
	}
	else if( opr == '+' || opr == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}