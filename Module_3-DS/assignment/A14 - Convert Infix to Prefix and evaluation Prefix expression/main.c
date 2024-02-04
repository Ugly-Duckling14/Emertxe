/*
Name : Munawir E
Date : 18/08/2022
Description : A14 - Convert Infix to Prefix and evaluation Prefix expression.
	Implement given below functions. 
		1.Infix_Prefix_conversion(char *Prefix_exp, char *Infix_exp, Stack_t *stk)
		2.Prefix_Eval(char *Prefix_exp, Stack_t *stk)
		3.priority(char opr)
*/
#include "main.h"

void strrev(char *string)
{
	int len, i;
	char temp;
    /* TODO: Write logic for string reverse */
	len = strlen(string);

	for( i = 0; i < len / 2; i++)
	{
		temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}	
}

int main()
{
	char Infix_exp[50], Prefix_exp[50];
	int result;
	Stack_t stk;
	stk.top = -1;

	printf("Enter the Infix expression : ");
	scanf("%s", Infix_exp);

	strrev(Infix_exp);
	Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);
	strrev(Prefix_exp);
	printf("PreFix expression : %s\n", Prefix_exp);

	stk.top = -1;

	strrev(Prefix_exp);
	result = Prefix_Eval(Prefix_exp, &stk);
	printf("\nResult : %d\n", result);
	return 0;
}
