#include "main.h"
/* function to convert the given infix expression into the prefix form.
 * Inputs: Prefix_exp - Pointer the base address of the postfix array.
 *         stk - Pointer to the stk.
 * Output: convert infix to prefix.
 */
int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    while( *Infix_exp != '\0')
    {
        // Checking the array element is operand.
        if( isdigit(*Infix_exp))
        {
            *Prefix_exp = *Infix_exp;
            Prefix_exp++;
        }
        else
        {
            // If it is a operator then and stack is empty then push it to stack.
            if( stk->top == -1 )
            {
                if( *Infix_exp == ')' || *Infix_exp == '+' || *Infix_exp == '-' || *Infix_exp == '*' || *Infix_exp == '/' || *Infix_exp == '%')
                {
                    push( stk, *Infix_exp);
                }
            }
            else
            {
                // Checking the operator is "(" then push to stack.
                if( *Infix_exp == ')')
                {
                    push(stk, *Infix_exp);
                }   
                else if( *Infix_exp == '(')      // If the operator is ")".
                {
                    while( stk->stack[stk->top] != ')')
                    {
                        // Store the element to prefix array till reaches "(" in stack.
                        *Prefix_exp = peek(stk);
                        Prefix_exp++;
                        pop(stk);
                    }
                    if( stk->top != -1)
                    {
                        pop(stk);
                    }
                }
                else
                {
                    // If item in stack is greater then store to prefix array.
                    while( priority(peek(stk)) > priority(*Infix_exp))
                    {
                        *Prefix_exp = peek(stk);
                        Prefix_exp++;
                        pop(stk);
                    }
                    push(stk, *Infix_exp);
                }
            }
        }
        Infix_exp++;
    }

    // Storing the remaining operand to prefix array.
    while( stk->top != -1)
    {
        *Prefix_exp = peek(stk);
        Prefix_exp++;
        pop(stk);
    }
    *Prefix_exp = '\0';
    return 0;
}