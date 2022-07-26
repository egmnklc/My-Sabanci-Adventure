/*  
    *-Function pointer is a pointer to a function,
    * not to a memory location.

    *- Useful when you don't know to call which function.

    ! Function pointer syntax:
    *- Type ( * PointerName ) (Parameter list) // Write only the types with ,
        *- Type must match the function's return type.
        *- Parameter list must match the function's parameters list.
        *- Don't forget to put paranthesis before and after PointerName.
    
    *- When you want to assign a function to a pointer, you get the
    *-  address of function using & and assign it to the function pointer:
    *-      PointerName = & FunctionName; 
    *-      //Writing only the FunctionName allows you to assign the memloc.
    *-      // Return type and the parameters of both sides myst be the same.

    *- When you want to call the function using function pointer use:
    *-      (* PointerName) (Argument list)
    *-      We put * before PointerName to dereference it.
*/

#include <iostream>

using namespace std;

//* Demonstrates the pointers to functions (a.k.a. function pointers)

int addition (int a, int b)
{
    return a + b;
}

int subtraction (int a, int b)
{
    return a - b;
}

//* Observe that parameters of both functions and return types 
//* are exactly the same.


int operation (int x, int y, int (*fptr)(int, int))
// ! As the third parameter, a desired function with same amount and type
// !    will be given, its return type must match with operation function's
// !    type as well. 

//* 3rd paramter is a parameter for a function pointer 
//* that returns int and takes two int parameters.
{
    int g;
    g = (*fptr)(x, y); //* Function is called using function pointer.
    return g;
}

int main()
{
     //* Create a function pointer with 2 int parameters.
    int (*p)(int, int);
    
    //* Set function pointer's memory location to substraction's memloc.
    p = & subtraction;
    //* Call to substraction function using function pointer.
    cout << (*p)(10, 20) << endl;
    
    
    int m, n;
    m = operation (7, 5, &addition); //* Passing a function as argument.
    n = operation (8, 10, &subtraction); 
    
    cout << m << " " << n << endl;

    return 0;
}