/* 
    -----------------------------------------------------------------------------
    What is post fix expression? 
        - The operators are after the operand. Classical mathematical expressions 
        are called as infix expressions.
    *- In the post fix expressions, 4 7 + means 11.
    *- When an operator is seen, it is applied to the previous two
    *   operands and the result is replaced.
    * You don't need to use any paranthesis.
    ! We assume operands are single char so that we can read char by char
    -----------------------------------------------------------------------------
*/

#include <iostream>
#include "DynIntStack.h"

using namespace std;


int main()
{
    DynIntStack stack;
    char token;
    int rhs, lhs, result;

    cout << "Please enter postfix expression: "; 

    while (cin >> token)
    {
        if (token >= '0' && token <= '9')
        {
            stack.push(token-'0');

        }

        else
        {
            stack.pop(rhs);
            stack.pop(lhs);
            
            if (token == '+')
            {
                stack.push(lhs + rhs);
            }

            else if (token == '-' )
            {
                stack.push(lhs-rhs);
            }

            else if (token == '*')
            {
                stack.push(rhs*lhs);
            }

            else if (token == '/')
            {
                stack.push(lhs/rhs);
            }
        }
    }
    // After while, the stack only contains the final result
    // Pop result and display.
    stack.pop(result);

    cout << "Result is: " << result << endl; 


    /*
        * int a = 47*; 28
        * int b =  472+*; 36
        * int c = 47*9-; (4*7 - 9) = 19
        * int d = 347*2/+; 4*7 / 2 + 3 = 17
        * int e = 472+*9-; 7+2 * 4 - 9 = 27
    */
    
    return 0;
}