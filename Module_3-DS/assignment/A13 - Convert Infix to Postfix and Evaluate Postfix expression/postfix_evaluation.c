
#include "main.h"

/* Function to Evaluate the postfix value.
 * Inputs: postfix_exp - Pointer the base address of the postfix array.
 *         stk - Pointer to the stk.
 * Output: return the result after postfix evaluation.
 * Description: Evaluate th postfix expression and return the result.
 */
int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    // Initalizing the variables.
    int oprnd1, oprnd2, res = 0;
    char opr, temp = '\0';

    // Evaluation the postfix expression.
    while( *Postfix_exp != '\0')
    {
        // Checking for operands
        if( *Postfix_exp >= 48 && *Postfix_exp <= 57 )
        {
            if( !(temp >= 48 && temp <= 57))
            {
                push( stk, (*Postfix_exp)-48);
            }

           // For Multi digit.
            else
            {
                stk -> stack[stk -> top] = (peek(stk) * 10) + (*Postfix_exp)-48;
            }
            
        }
        else
        {
            if( *Postfix_exp != ',')
            {
                // Storing values for evaluation.
                oprnd2 = peek(stk);
                pop(stk);
                oprnd1 = peek(stk);
                pop(stk);
                opr = *Postfix_exp;

                // Performing the operation.
                switch( opr)
                {
                    case '+' :
                    {
                    res = oprnd1 + oprnd2;
                        break;
                    }
                    case '-' :
                    {
                        res = oprnd1 - oprnd2;
                        break;
                    }
                    case '*' :
                    {    res = oprnd1 * oprnd2;
                        break;
                    }
                    case '/' :
                    {       res = oprnd1 / oprnd2;
                        break;
                    }
                }

                // Storing the result to stack.
                push(stk, res);
            }
        }
        // temp = *Postfix_exp;
        
        Postfix_exp++;
    }

    // Taking final resulr from stack.
    res = peek(stk);
    pop(stk);

    // Returning the result.
    return res; 
}