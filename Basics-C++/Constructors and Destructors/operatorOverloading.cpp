/* 

    Overloading is the practice of supplying more than one 
    definition for a given function name. 

    The compiler pirkcs the appropriate version of the function
    or operator based on the arguments with which it is called.

    In case of an ambiguity, syntax error occurs. 

    Both free and member functions can be overloaded


    double max( double d1, double d2 )
    {
        if (d1 > d2) return d1;
        else return d2;
    }

    int max (int i1, int i2 )
    {
        if (i1 > i2) return i1;
        else return i2;
    }

    int main()
    {
        int i = max( 12,8 ); // calls second one
        double d = max ( 17.4, 32.9); // calls first one
    }

    ! Depending the type of arguments, proper type of function 
    ! is called and this is decided by the compiler.

    max (4, 5.2) will cause syntax error because there
    is ambiguity. One is int and other is real.

    ----------------------------------------------------------------

    ! Writing Function for Operators and Operator Overloading

    * Syntax for function header for operators
    *   Return_Type classname::operator Operator_Symbol(parameters)
    *  
    * const myclass & myclass::operator = (const myclass & rhs)
    * const linkedlist & mylist::operator = (const linkedlist & list1)
    * 
    * Assignment operator is a special one, it must be a member function,
    * not a free function.
    * 
    *  


*/