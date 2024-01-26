#ifndef INTSTACK_H
#define INTSTACK_H

/*
    * consturctor: Initializes top to -1, to create an empty stack.
    Class constructor accepts an integer as an argument, which
    specifies the size of the stack. An integer array of this size
    is dynamically allocated, and assigned to StackArray. Also the 
    top variable is initialized to -1.

    that stores the index of top stack.
    *top: Stored as a private member, it is an integer value

    *stackSize: Max # of elements to be put in a stack, integer.
    
    *stackArray: A pointer to int, when consturctor is executed,
    it uses stackArray to dynamically allocate an array for storage.
    In the consturction, we'll use new in order to allocate memory.

*/

class IntStack
{
    private:
        int *stackArray;
        int stackSize;
        int top;
    
     public:
        IntStack(int); // Constructor, int is the size.
        void push(int); // The new value that you want to push on the stack
        void pop(int &); // Should return the newly added first value
        /* 
            You either return as the function's return value
                                or
                    as a referance parameter

            This example returns as a reference parameter
        */
        bool isFull(void); // void means it takes no parameters
        bool isEmpty(void); // You don't need to put in void here


};

#endif