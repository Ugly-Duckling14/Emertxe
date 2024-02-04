#include "main.h"

/* Function to evaluate the prefix expression.
 * Inputs: Prefix_exp - Pointer the base address of the postfix array.
 *         stk - Pointer to the stk.
 * Output: return the result after evaluation.
 */
int Prefix_Eval(char *Prefix_exp, Stack_t *stk)
{
    // Initalizing the variables.
    int oprnd1, oprnd2, res = 0;
    char opr;

    // Evaluating the prefix expression.
    while( *Prefix_exp != '\0')
    {
        // Checking for operands
        if( isdigit(*Prefix_exp) )
        {
            push( stk, (*Prefix_exp)-48);
        }
        else
        {
            // Storing values for evaluation.
            oprnd1 = peek(stk);
            pop(stk);
            oprnd2 = peek(stk);
            pop(stk);
            opr = *Prefix_exp;
            
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
                {
                    res = oprnd1 * oprnd2;
                    break;
                }
                case '/' :
                {       
                    res = oprnd1 / oprnd2;
                    break;
                }
                case '%' :
                {
                    res = oprnd1 % oprnd2;
                }
            }
            // Storing the result to stack.
            push(stk, res);   
        }
        Prefix_exp++;
    }

    // Taking final resulr from stack.
    res = peek(stk);
    pop(stk);

    // Returning the result.
    return res; 
}