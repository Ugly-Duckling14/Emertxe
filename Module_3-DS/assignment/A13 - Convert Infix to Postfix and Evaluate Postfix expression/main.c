/*
Name : Munawir E
Date : 18/08/2022
Description : A13 - Convert Infix to Postfix and Evaluate Postfix expression
	Implement given below functions.
		Infix_Postfix_conversion(Infix_exp, Postfix_exp, &stk)
		Postfix_Eval(Postfix_exp, &stk)
	Note :- For multi digits is commented.
*/

#include "main.h"
#include <string.h>

int main()
{
	char Infix_exp[50], Postfix_exp[50];
	int result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	Infix_Postfix_conversion(Infix_exp, Postfix_exp, &stk);
	printf("PostFix expression : %s\n", Postfix_exp);
	stk.top = -1;
	result = Postfix_Eval(Postfix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}
