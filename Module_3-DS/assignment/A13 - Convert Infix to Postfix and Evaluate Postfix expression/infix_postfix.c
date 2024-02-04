#include "main.h"

/* Function to convert infix to postfix
 * Inputs: Infix_exp - Pointer the base address of the infix array
 *         stk - Pointer to the stk.
 * Output: Returns Postfix array. 
 */
int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    //char temp;

    // Loop runs till infix array not a NULL.
    while( *Infix_exp != '\0')
    {
       // temp = *Infix_exp;

        // Checking the input is integer/operand.
        if( isdigit(*Infix_exp) )
        {
            *Postfix_exp = *Infix_exp;
            Postfix_exp++;
        }
        else
        { 
            // If it is a operator then and stack is empty then push it to stack.
            if( stk->top == -1 )
            {
                if( !(isdigit(*Infix_exp) && *Infix_exp != ')'))
                {
                    push( stk, *Infix_exp);
                }
            }
            else
            {
                // Checking the operator is "(" then push to stack.
                if( *Infix_exp == '(')
                {
                    push(stk, *Infix_exp);
                }   
                else if( *Infix_exp == ')')      // If the operator is ")".
                {
                    while( stk->stack[stk->top] != '(')
                    {
                        // Store the element to postfix array till reaches "(" in stack.
                        *Postfix_exp = peek(stk);
                        Postfix_exp++;
                        pop(stk);
                    }
                    if( stk->top != -1)
                    {
                        pop(stk);
                    }
                }
                else
                {
                    // Checking the priority of the operator.
                    if( priority(peek(stk)) >= priority(*Infix_exp))
                    {
                        *Postfix_exp = peek(stk);
                        Postfix_exp++;
                        pop(stk);
                        push(stk, *Infix_exp);
                    }
                    else
                    {
                        push(stk, *Infix_exp);
                    }
                }
            }
        }
        Infix_exp++;

        // * For multi digits
        // if( !(isdigit(*(Postfix_exp - 1)) && *(Postfix_exp - 1) != ')') && isdigit(temp))
        // {
        //     *Postfix_exp = ',';
        //     Postfix_exp++;
        // }
        
    }
    while( stk->stack[stk->top] != -1)
    {
        *Postfix_exp = peek(stk);
        Postfix_exp++;
        pop(stk);
       
       // For Multi digit
    //     if( *(Postfix_exp-1) == '+' || *(Postfix_exp-1) == '-' || *(Postfix_exp-1) == '*' || *(Postfix_exp-1) == '/')
    //     {
    //        //*Postfix_exp = ',';
    //        Postfix_exp++; 
    //     }
        
    }
    *Postfix_exp = '\0';
    return 0;
}